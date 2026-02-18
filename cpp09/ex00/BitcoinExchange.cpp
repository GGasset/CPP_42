
#include "BitcoinExchange.hpp"
#include <cctype>
#include <exception>

static int is_valid_date(const date &d)
{
	int year = d.get_ymd()[0];
	bool is_leap = year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);

	int month_lengths[12];
	month_lengths[0] = 31;
	month_lengths[1] = 28 + is_leap;
	month_lengths[2] = 31;
	month_lengths[3] = 30;
	month_lengths[4] = 31;
	month_lengths[5] = 30;
	month_lengths[6] = 31;
	month_lengths[7] = 31;
	month_lengths[8] = 30;
	month_lengths[9] = 31;
	month_lengths[10] = 30;
	month_lengths[11] = 31;

	int month = d.get_ymd()[1];
	if (month > 12 || month <= 0) return 0;

	int day = d.get_ymd()[2];
	return day <= month_lengths[month - 1] && day > 0;
}

date::date()
{
	for (size_t i = 0; i < 3; i++) ymd[i] = 1;
}

date::date(unsigned short year, unsigned short month, unsigned short day)
{
	ymd[0] = year;
	ymd[1] = month;
	ymd[2] = day;
	if (!is_valid_date(*this)) throw std::exception();
}

date::date(const date &src)
{
	if (!is_valid_date(src)) throw std::exception();

	for (size_t i = 0; i < 3; i++) ymd[i] = src.ymd[i];
}

date &date::operator=(const date &src)
{
	if (!is_valid_date(src)) throw std::exception();

	for (size_t i = 0; i < 3; i++) ymd[i] = src.ymd[i];

	return *this;
}

date::~date()
{

}

int date::compare(const date &other) const
{
	if (ymd[0] != other.ymd[0]) return (int)ymd[0] - other.ymd[0];
	if (ymd[1] != other.ymd[1]) return (int)ymd[1] - other.ymd[1];
	return (int)ymd[2] - other.ymd[2];
}

bool date::operator<(const date &other) const
{
	return compare(other) < 0;
}
bool date::operator<=(const date &other) const
{
	return compare(other) <= 0;
}
bool date::operator>(const date &other) const
{
	return compare(other) > 0;
}
bool date::operator>=(const date &other) const
{
	return compare(other) >= 0;
}


unsigned short *date::get_ymd()
{
	return ymd;
}

const unsigned short *date::get_ymd() const
{
	return ymd;
}

std::ostream &operator<<(std::ostream &s, date &d)
{
	unsigned short *ymd = d.get_ymd();

	for (size_t i = 0; i < 3; i++)
	{
		if (i == 0)
			s << ymd[0];
		else
		{
			if (ymd[i] < 10) s << "0";
			s << ymd[i];
		}
		if (i != 2) s << "-";
	}
	return s;
}

void expect_str(const std::string &str, size_t &str_pos, const std::string expected_str, int &err, bool print_err)
{
	size_t i;
	for (i = 0; str[str_pos] && expected_str[i] && str[str_pos] == expected_str[i]; i++, str_pos++) {}

	if (!expected_str[i]) return;

	err = true;
	if (!print_err) return;
	std::cout << "expected \"" << expected_str << "\"" << std::endl;
	std::cout << "In line \"" << str << "\"" << std::endl;
	return;
}

static int mstoi(std::string in, size_t *len = 0)
{
	std::stringstream ss;
	if (len) *len = 0;
	for (size_t i = 0; std::isdigit(in[i]); i++, len? (*len)++ : 0)
	{
		ss << in[i];
	}
	int out = 0;
	ss >> out;
	return out;
}

float parse_check_value(const std::string &str, size_t &str_pos, int &err, bool print_err, bool is_date)
{
	err = 0;
	std::string tmp = str;
	float out = 0;
	try
	{
		tmp.erase(0, str_pos);

		while (tmp[0] == '0') tmp.erase(0, 1);

		if (std::isdigit(tmp[0]))
		{
			size_t integer_len = 0;
			out = (float)mstoi(tmp, &integer_len);
			tmp.erase(0, integer_len);
			if (integer_len == 0 && (!is_date || tmp[0] != '.')) {
				if (print_err) std::cout << "Expected number at line \"" << str << "\"" << std::endl;
				err = true; return 0;
			}
		}

		if (tmp[0] == '.' && !is_date)
		{
			tmp.erase(0, 1);

			size_t removed_0_n = 0;
			while (tmp[0] == '0') {tmp.erase(0, 1); removed_0_n++;}

			float decimal_part = mstoi(tmp);
			while (decimal_part >= 1) decimal_part /= 10;
			while (removed_0_n) {decimal_part /= 10; removed_0_n--;}

			out += decimal_part;
		}

	} catch (const std::exception &e) {
		err = true;
		if (print_err) std::cout << "Invalid number at line \"" << str << "\"" << std::endl;
		return 0;
	}

	if (!is_date && (out < 0 || out >= 1000)) {
		if (print_err) std::cout << "Invalid value " << out << " at line \"" << str << "\"" << std::endl;
		err = true;
		return 0;
	}

	size_t value_len = 0;
	while (std::isdigit(str[str_pos])) {str_pos++; value_len++;}
	if (is_date || str[str_pos] != '.')
	{
		if (!value_len) {
			if (print_err) std::cout << "Expected number at line \"" << str << "\"" << std::endl;
			err = true; return 0;
		}
		return out;
	}
	str_pos++;
	while (std::isdigit(str[str_pos])) {str_pos++; value_len++;}
	if (!value_len) {
		if (print_err) std::cout << "Expected number at line \"" << str << "\"" << std::endl;
		err = true; return 0;
	}
	return out;
}

date parse_check_date(const std::string &str, size_t &str_pos, int &err, bool print_err)
{
	int values[3];

	err = 0;
	values[0] = parse_check_value(str, str_pos, err, print_err, true);
	if (err) return date();

	expect_str(str, str_pos, "-", err, print_err);
	if (err) return date();

	values[1] = parse_check_value(str, str_pos, err, print_err, true);
	if (err) return date();

	expect_str(str, str_pos, "-", err, print_err);
	if (err) return date();

	values[2] = parse_check_value(str, str_pos, err, print_err, true);
	if (err) return date();

	try {
		date d(values[0], values[1], values[2]);
		return d;

	} catch (std::exception) {
		if (print_err) std::cout << "Invalid date at line \"" << str << "\", not a real date." << std::endl;
		err = true;
		return date();
	}
}

dated_quantity parse_check_infile_line(const std::string &line, int &err)
{
	dated_quantity out;

	size_t str_pos = 0;
	date d = parse_check_date(line, str_pos, err, true);
	if (err) return out;
	expect_str(line, str_pos, " | ", err, true);
	if (err) return out;
	float quantity = parse_check_value(line, str_pos, err, true, false);
	if (err) return out;

	out.d = d;
	out.n = quantity;
	return out;
}

dated_quantity parse_check_db_file_line(const std::string &line, int &err)
{
	dated_quantity out;

	size_t str_pos = 0;
	date d = parse_check_date(line, str_pos, err, false);
	if (err) return out;
	expect_str(line, str_pos, ",", err, false);
	if (err) return out;
	float quantity = parse_check_value(line, str_pos, err, false, false);
	if (err) return out;

	out.d = d;
	out.n = quantity;
	return out;
}

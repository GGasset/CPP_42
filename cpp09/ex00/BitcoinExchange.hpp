
#ifndef PARSING_HPP
#define PARSING_HPP

#include <cstdint>
#include <iostream>
#include <string>

class date
{
private:
	uint16_t ymd[3];

public:
	// Inits to 0
	date();
	date(uint16_t year, uint16_t month, uint16_t day);
	date(const date &src);
	date &operator=(const date &src);
	~date();

	int compare(const date &other) const;
	bool operator<(const date &other) const;
	bool operator<=(const date &other) const;
	bool operator>(const date &other) const;
	bool operator>=(const date &other) const;

	uint16_t *get_ymd();
};

std::ostream &operator<<(std::ostream &, date &);

struct dated_quantity
{
	date d;
	float n;
};

void expect_str(const std::string &str, size_t &str_pos, const std::string expected_str, int &err, bool print_err);
float parse_check_value(const std::string &str, size_t &str_pos, int &err, bool print_err, bool is_date);
date parse_check_date(const std::string &str, size_t &str_pos, int &err, bool print_err);

dated_quantity parse_check_infile_line(const std::string &line, int &err);
dated_quantity parse_check_db_file_line(const std::string &line, int &err);



#endif

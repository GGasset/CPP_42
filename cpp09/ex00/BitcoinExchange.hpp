
#ifndef PARSING_HPP
#define PARSING_HPP

//#include <cstdint>
#include <iostream>
#include <string>
#include <cctype>
#include <sstream>

class date
{
private:
	unsigned short ymd[3];

public:
	// Inits to 0
	date();
	date(unsigned short year, unsigned short month, unsigned short day);
	date(const date &src);
	date &operator=(const date &src);
	~date();

	int compare(const date &other) const;
	bool operator<(const date &other) const;
	bool operator<=(const date &other) const;
	bool operator>(const date &other) const;
	bool operator>=(const date &other) const;

	unsigned short *get_ymd();
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

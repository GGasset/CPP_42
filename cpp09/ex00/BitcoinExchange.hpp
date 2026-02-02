
#ifndef PARSING_HPP
#define PARSING_HPP

#include <string>

class date
{
private:
	float year;
	float month;
	float day;

public:
	// Inits to 0
	date();
	date(float year, float month, float day);
	date(const date &src);
	date &operator=(const date &src);
	~date();

	bool operator<(const date &other) const;
	bool operator<=(const date &other) const;
	bool operator>(const date &other) const;
	bool operator>=(const date &other) const;
};

struct dated_quantity
{
	date d;
	float n;
};

float parse_check_value(const std::string &str, int &err);
date parse_check_date(const std::string &str, int &err);

dated_quantity parse_check_infile_line(const std::string &str, int &err);
dated_quantity parse_check_db_file_line(const std::string &str, int &err);



#endif


#include "BitcoinExchange.hpp"
#include <cctype>
#include <fstream>
#include <iostream>
#include <list>
#include <ostream>

#define USAGE "USAGE: ./btc file"

static std::string read_file(const std::string &filename, int &err)
{
	err = false;
	std::string file_contents;

	std::fstream file;
	file.open(filename.c_str());
	if (!file.is_open() || !file.good()) {err = true; return "";}

	size_t bytes_read;
	const size_t buff_size = 42;
	char tmp[buff_size + 1];
	do {
		for (size_t i = 0; i < buff_size + 1; i++) tmp[i] = 0;
		file.read(tmp, buff_size);
		bytes_read = file.gcount();

		file_contents += tmp;

	} while (bytes_read == buff_size);

	file.close();
	return file_contents;
}

static std::list<std::string> read_lines(const std::string &filename, int &err)
{
	std::list<std::string> lines;
	std::string raw = read_file(filename, err);
	if (err) return lines;

	std::string tmp;
	for (size_t i = 0; i < raw.size(); i++)
	{
		if (raw[i] == '\n')
		{
			lines.push_back(tmp);
			tmp = "";
			continue;
		}
		tmp += raw[i];
	}
	return lines;
}

void search_value(dated_quantity btc_possesion, std::list<dated_quantity> btc_values)
{
	bool found_upper_match = false;
	dated_quantity match;
	match.d = date(1.5e3,12, 31);
	for (std::list<dated_quantity>::iterator it = btc_values.begin(); it != btc_values.end(); it++)
	{
		if ((*it).d >= btc_possesion.d && it->d < match.d) {match = *it; found_upper_match = true;}
	}
	if (!found_upper_match) match.d = date();
	for (std::list<dated_quantity>::iterator it = btc_values.begin(); it != btc_values.end() && !found_upper_match; it++)
	{
		if (it->d >= match.d) match = *it;
	}

	std::cout << btc_possesion.d << " => " << btc_possesion.n << " = " << btc_possesion.n * match.n << std::endl;
}

void execute_n_parse_infile(std::list<std::string> infile_contents, std::list<dated_quantity> btc_values)
{
	int err;
	for (std::list<std::string>::iterator line_it = infile_contents.begin(); line_it != infile_contents.end(); line_it++)
	{
		if (line_it == infile_contents.begin())
		{
			if  (*infile_contents.begin() != "date | value") {std::cout << "Invalid infile header. Ignoring it..." << std::endl;}
			else continue;
		}
		std::string line = *line_it;

		bool is_empty = true;
		for (size_t i = 0; i < line.size() && is_empty; i++) is_empty = is_empty && (!std::isprint(line[i]) || std::isspace(line[i]));
		if (is_empty) continue;

		err = 0;
		dated_quantity parsed = parse_check_infile_line(line, err);
		if (err) continue;

		search_value(parsed, btc_values);
	}
}

int main(int argc, char **argv)
{
	if (argc != 2) {std::cout << USAGE << std::endl; return 0;}

	int err = 0;
	std::list<std::string> infile_contents = read_lines(argv[1], err);
	if (err) {std::cout << "Could not open file " << argv[1] << "." << std::endl; return 0;}

	std::list<std::string> db_contents = read_lines("./data.csv", err);
	if (err) {std::cout << "Could not open file ./data.csv, it must be present at working directory." << std::endl; return 0;}

	size_t valid_db_lines = 0;
	std::list<dated_quantity> btc_values;
	for (std::list<std::string>::iterator db_iter = db_contents.begin(); db_iter != db_contents.end(); db_iter++)
	{
		if (db_iter == db_contents.begin())
		{
			if  (*db_contents.begin() != "date,exchange_rate") {std::cout << "Invalid db header. Ignoring it..." << std::endl;}
			else continue;
		}
		err = 0;
		btc_values.push_back(parse_check_db_file_line(*db_iter, err));
		if (err) continue;

		valid_db_lines++;
	}
	if (!valid_db_lines) {std::cout << "./data.csv DB does not contain any valid line. Aborting" << std::endl; return 0;}

	execute_n_parse_infile(infile_contents, btc_values);
}


#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <list>

#define USAGE "USAGE: ./btc file"

static std::string read_file(const std::string &filename, int &err)
{
	err = false;
	std::string file_contents;

	std::fstream file;
	file.open(filename);
	if (!file.is_open() || !file.good()) {err = true; return "";}

	size_t bytes_read;
	const size_t buff_size = 42;
	char tmp[buff_size + 1];
	do {
		for (size_t i = 0; i < buff_size + 1; i++) tmp[i] = 0;
		file.read(tmp, buff_size);

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

int main(int argc, char **argv)
{
	if (argc != 2) {std::cout << USAGE << std::endl; return 0;}

	int err = 0;
	std::list<std::string> infile_contents = read_lines(argv[1], err);
	if (err) {std::cout << "Could not open file " << argv[1] << "." << std::endl; return 0;}

	std::list<std::string> db_contents = read_lines("./data.csv", err);
	if (err) {std::cout << "Could not open file " << "./data.csv" << "." << std::endl; return 0;}

	std::list<dated_quantity> btc_values;
	for (size_t i = 0; i < db_contents.size(); i++)
	{

	}

	for (std::list<std::string>::iterator it = infile_contents.begin(); it != infile_contents.end(); it++)
	{
		err = 0;
		dated_quantity parsed = parse_check_infile_line(*it, err);
		if (err) continue;

		bool found_upper_match = false;
		dated_quantity match;
		for (std::list<dated_quantity>::iterator it = btc_values.begin(); it != btc_values.end(); it++)
		{
			if (*it >= parsed && *it < match) {match = *it; found_upper_match = true;}
		}
	}
}

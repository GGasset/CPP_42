#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string literal)
{
	std::string str;
	std::stringstream ss;
	std::string tmp;

	bool start_copy = false;
	for (size_t i = 0; i < literal.size(); i++)
	{
		start_copy = start_copy || !isspace(literal[i]);
		if (start_copy && isspace(literal[i]))
			break;
		
		str += literal[i];
	}

	std::string lower;
	for (size_t i = 0; i < str.size(); i++) lower += std::tolower(str[i]);

	const char *special_literals[] = {"-inff", "inff", "nanf", "minf", "inf", "nan", 0};
	size_t special_i = 0;
	for (size_t i = 0; special_literals[i] && !special_i; i++) if (special_literals[i] == lower) special_i = i;
	if (special_i)
	{
		switch (special_i - 1)
		{
		case minff:
		case minf:
			print("impossible", "impossible", "-inff", "-inf");
			break;

		case inff:
		case inf:
			print("impossible", "impossible", "inff", "inf");
			break;

		case nanf:
		case nan:
			print("impossible", "impossible", "nanf", "nan");
			break;
		
		default: throw;
		}
	}

	if (!isdigit(str[0]) && str.size() == 1) // Char
	{
		ScalarRepresentation(character, (int)literal[0]).print();
		return;
	}

	char last_char = std::tolower(*(str.end() - 1));
	for (size_t i = 0; i < str.size() - (last_char == 'f'); i++)
		if (!isdigit(str[i]) && str[i] != '.' && str[i] != '-') 
		{
			std::cerr << "Invalid literal, non digit withing a multiple char literal" << std::endl;
			return;
		}

	bool contains_dot = false;
	for (size_t i = 0; str[i] && !contains_dot; i++) contains_dot = str[i] == '.';

	if (!contains_dot && last_char != 'f') // Int
	{
		int n = std::atoi(str.data());
		ss << n;
		if (ss.str() != str)
		{
			std::cerr << "Overflow with provided literal" << std::endl;
			return;
		}
		
		ScalarRepresentation(integer, n).print();
		return;
	}

	// Check double overflow

	if (last_char != 'f') // Double
	{

	}

	// Float

	double n = std::atof(str.data());
	if ((float)n != n)
	{
		std::cerr << "Overflow with provided literal" << std::endl;;
		return;
	}
	ScalarRepresentation(floating_point, (float)n).print();
}
#include "ScalarConverter.hpp"

ScalarConverter::ScalarRepresentation::ScalarRepresentation(ScalarRepresentation &src)
{*this = src;}

ScalarConverter::ScalarRepresentation &ScalarConverter::ScalarRepresentation::operator=(ScalarRepresentation &src)
{
	type = src.type;
	number = src.number;
	return *this;
}

ScalarConverter::ScalarRepresentation::ScalarRepresentation(ScalarConverter::literal_type type, double number)
{
	this->type = type;
	this->number = number;
}

ScalarConverter::ScalarRepresentation::~ScalarRepresentation() {}

void ScalarConverter::ScalarRepresentation::print()
{
	bool isInteger = number == (double)(int)number;
	bool isDisplayable = isInteger && number >= ' ' && number <= '~';

	std::stringstream ss;
	std::string c;
	std::string i;
	std::string f;
	std::string d;

	if (!isInteger)
	{
		c = "Imposible";
		i = "Imposible";
	}
	else if (!isDisplayable)
		c = "Non displayable";

	if (!c.size()) c += (char)number;
	if (!i.size())
	{
		ss << (int)number;
		i = ss.str();
		ss.str("");
	}
	ss << (float)number;
	if (isInteger) ss << ".0";
	ss << "f";
	f = ss.str();
	ss.str("");

	ss << number;
	if (isInteger) ss << ".0";
	d = ss.str();
	ss.str("");

	ScalarConverter::print(c, i, f, d);
}


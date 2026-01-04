
#ifndef CONVERT_HPP
#define CONVERT_HPP

#include "cstdlib"
#include "iostream"
#include "string"
#include "sstream"
#include "cctype"

class ScalarConverter
{
private:
	enum literal_type
	{
		minff,
		inff,
		nanf,
		minf,
		inf,
		nan,

		double_prec_point,
		floating_point,
		character,
		integer
	};

	static void print(std::string c, std::string i, std::string f, std::string d);

	class ScalarRepresentation
	{
	public:
		ScalarConverter::literal_type type;
		double number;

		ScalarRepresentation(ScalarConverter::literal_type type, double number);
		ScalarRepresentation(ScalarRepresentation &src);
		ScalarRepresentation &operator=(ScalarRepresentation &src);
		~ScalarRepresentation();

		void print();
	};

	ScalarConverter();
	ScalarConverter(ScalarConverter &src);
	ScalarConverter &operator=(ScalarConverter &src);
	~ScalarConverter();
public:

	static void convert(std::string literal);
};

#endif

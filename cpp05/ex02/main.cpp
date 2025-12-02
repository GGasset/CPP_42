#include "Bureaucrat.hpp"
#include "iostream"

int main()
{
	try
	{
		AForm boring("Boring form", 0, 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		AForm boring("Boring form", 1, 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		AForm boring("Boring form", 151, 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		AForm boring("Boring form", 1, 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	AForm high("Too high form", 1, 1);
	AForm ok("Ok form", 28, 28);
	Bureaucrat e("e", 27);
	std::cout << e << std::endl;

	try
	{
		e.signForm(high);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	e.signForm(ok);
}

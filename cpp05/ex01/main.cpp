#include "Bureaucrat.hpp"
#include "iostream"

int main()
{
	try
	{
		Bureaucrat boring("Boring", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat boring("Boring", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		Bureaucrat boring("Boring", 150);
		boring += 1;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat boring("Boring", 1);
		boring -= 1;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form boring("Boring form", 0, 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form boring("Boring form", 1, 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form boring("Boring form", 151, 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form boring("Boring form", 1, 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	Form high("Too high form", 1, 1);
	Form ok("Ok form", 28, 28);
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

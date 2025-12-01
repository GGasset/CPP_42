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

	std::cout << Bureaucrat("Boring", 1) << std::endl;
}

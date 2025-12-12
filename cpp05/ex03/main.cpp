#include "iostream"

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	Intern intern;

	AForm *tmp;

	tmp = intern.makeForm("presidential pardon", "Zaphood Betlebrox");
	std::cout << *tmp << std::endl;
	delete tmp;

	tmp = intern.makeForm("shrubbery creation", "Me");
	std::cout << *tmp << std::endl;
	delete tmp;

	tmp = intern.makeForm("robotomy request", "Bender");
	std::cout << *tmp << std::endl;
	delete tmp;

	std::cout << intern.makeForm("Formn't", "Me") << std::endl;
}

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &src)
{
	src.~Intern();
}

Intern &Intern::operator=(const Intern &src)
{
	src.~Intern();
	return *this;
}

Intern::~Intern()
{
}

AForm *Intern::makeForm(std::string formName, std::string Target)
{

	const char *forms[] = {"presidential pardon", "shrubbery creation", "robotomy request", 0};

	size_t form_i;
	for (form_i = 0; forms[form_i]; form_i++)
	{
		std::string form = forms[form_i];
		if (form == formName)
			break;
	}

	AForm *out = 0;
	switch (form_i)
	{
	case 0:
		out = new PresidentialPardonForm(Target);
		break;
	case 1:
		out = new ShrubberyCreationForm(Target);
		break;
	case 2:
		out = new RobotomyRequestForm(Target);
		break;
	default:
		std::cerr << "Intern tried to create an invalid form" << std::endl;
		return 0;
	}
	std::cout << "Intern created " << formName << std::endl;
	return out;
}
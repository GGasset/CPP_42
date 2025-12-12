#include "iostream"

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat ZaphodBeeblebrox = Bureaucrat("Zaphod Beeblebrox", 1);

	AForm *PardonForm = new PresidentialPardonForm("Pardon target");
	AForm *RobotomyForm = new RobotomyRequestForm("Robotomy target");
	AForm *ShrubberyForm = new ShrubberyCreationForm("Shrubbery target");

	ZaphodBeeblebrox.signForm(ShrubberyForm);
	ZaphodBeeblebrox.signForm(RobotomyForm);
	ZaphodBeeblebrox.signForm(PardonForm);

	ZaphodBeeblebrox.executeForm(*ShrubberyForm);
	ZaphodBeeblebrox.executeForm(*RobotomyForm);
	ZaphodBeeblebrox.executeForm(*PardonForm);

	Bureaucrat RigobertoMenendez = Bureaucrat("Rigoberto Menendez", 150);
	AForm *RigobertoPardonForm = new PresidentialPardonForm("Rigoberto Menendez");
	try
	{
		RigobertoMenendez.signForm(RigobertoPardonForm);
		RigobertoMenendez.executeForm(*RigobertoPardonForm);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	ZaphodBeeblebrox.signForm(RigobertoPardonForm);
	ZaphodBeeblebrox.executeForm(*RigobertoPardonForm);

	delete PardonForm;
	delete RobotomyForm;
	delete ShrubberyForm;
	delete RigobertoPardonForm;
}

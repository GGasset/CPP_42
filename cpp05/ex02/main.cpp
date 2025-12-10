#include "iostream"

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

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
}

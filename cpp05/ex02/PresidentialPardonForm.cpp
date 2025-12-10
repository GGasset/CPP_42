#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target): AForm("PresidentialPardonForm", 25, 5, target)
{
}

void PresidentialPardonForm::form_specific_execute(const Bureaucrat &executor) const
{
	std::cout << getTarget() << "Has been pardoned by Zaphod Beeblebrox." << std::endl; 
}

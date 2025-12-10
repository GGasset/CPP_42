
#ifndef PARDON_HPP
#define PARDON_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm(const std::string target);
	void form_specific_execute(const Bureaucrat &executor) const;
};

#endif

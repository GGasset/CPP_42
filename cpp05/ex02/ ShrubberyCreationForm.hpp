
#ifndef  ShrubberyCreationForm_HPP
#define  ShrubberyCreationForm_HPP

#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
public:
	ShrubberyCreationForm();
	void form_specific_execute(Bureaucrat &executor);
};

#endif

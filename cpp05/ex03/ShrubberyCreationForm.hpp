
#ifndef  ShrubberyCreationForm_HPP
#define  ShrubberyCreationForm_HPP

#include "AForm.hpp"
#include "fstream"

class ShrubberyCreationForm: public AForm
{
public:
	ShrubberyCreationForm(const std::string target);
	void form_specific_execute() const;
};

#endif

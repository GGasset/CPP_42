#ifndef ROBOTOMY_HPP
# define ROBOTOMY_HPP

#include "AForm.hpp"
#include "cstdlib"

class RobotomyRequestForm: public AForm
{
public:
	RobotomyRequestForm(const std::string target);
	void form_specific_execute() const;
};

#endif

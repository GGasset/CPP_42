#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string target): AForm("RobotomyRequestForm", 72, 45, target)
{
}

void RobotomyRequestForm::form_specific_execute() const
{
	std::cout << getTarget() << " has been robotomized ";
	if (std::rand() & 1) std::cout << "successfully";
	else				 std::cout << "and the operation failed, warranty was voided by the operation";
	std::cout << std::endl;
}

#include "AForm.hpp"

AForm::AForm(): name("Unnamed Form"), is_signed(false), sign_req_grade(1), exec_req_grade(1)
{
}

AForm::AForm(const AForm &src): name(src.name), is_signed(src.is_signed), sign_req_grade(src.sign_req_grade), exec_req_grade(src.sign_req_grade)
{
}

AForm &AForm::operator=(AForm &src)
{
	is_signed = src.is_signed;
	return *this;
}

AForm::~AForm()
{
}

AForm::AForm(std::string _name, long _sign_req_grade, long _exec_req_grade): name(_name), sign_req_grade(_sign_req_grade), exec_req_grade(_exec_req_grade)
{
	if (_sign_req_grade < 1 || _exec_req_grade < 1) throw AForm::GradeTooHighException();
	if (_sign_req_grade > 150 || _exec_req_grade > 150) throw AForm::GradeTooLowException();
}

std::string AForm::getName() const
{
	return name;
}

bool AForm::get_is_signed() const
{
	return is_signed;
}

long AForm::get_sign_req_grade() const
{
	return sign_req_grade;
}

long AForm::get_exec_req_grade() const
{
	return exec_req_grade;
}

void AForm::beSigned(Bureaucrat signer)
{
	if (sign_req_grade < signer.getGrade()) throw AForm::GradeTooLowException();

	is_signed = true;
}

void AForm::execute(Bureaucrat &executor)
{
	if (exec_req_grade < executor.getGrade())
	{
		std::cout << *this << " could not be executed by " << executor << " (invalid grade)" << std::endl;
		throw AForm::GradeTooLowException();
	}
	if (!is_signed)
	{
		std::cout << *this << " could not be executed by " << executor << " (form is not signed)" << std::endl;
		throw AForm::FormNotSignedException();
	}
	form_specific_execute(executor);
	std::cout << executor << " executed " << *this << ". " << std::endl;
}

AForm::GradeTooHighException::GradeTooHighException(): std::runtime_error("Form grade too high.") {}
AForm::GradeTooLowException::GradeTooLowException(): std::runtime_error("Form grade too low.") {}

std::ostream &operator<<(std::ostream &stream, const AForm &in)
{
	std::stringstream ss;
	ss << in.getName() << ", signed: " << in.get_is_signed() << ", sign grade: " << in.get_sign_req_grade() << ", execute grade: " << in.get_exec_req_grade() << ".";
	stream << ss.str();
	return stream;
}

AForm::FormNotSignedException::FormNotSignedException(): std::runtime_error("Unsigned form was attempted to be executed.")
{
}

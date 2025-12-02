#include "Form.hpp"

Form::Form(): name("Unnamed Form"), is_signed(false), sign_req_grade(1), exec_req_grade(1)
{
}

Form::Form(const Form &src): name(src.name), is_signed(src.is_signed), sign_req_grade(src.sign_req_grade), exec_req_grade(src.sign_req_grade)
{
}

Form &Form::operator=(Form &src)
{
	is_signed = src.is_signed;
	return *this;
}

Form::~Form()
{
}

Form::Form(std::string _name, long _sign_req_grade, long _exec_req_grade): name(_name), sign_req_grade(_sign_req_grade), exec_req_grade(_exec_req_grade)
{
	if (_sign_req_grade < 1 || _exec_req_grade < 1) throw Form::GradeTooHighException();
	if (_sign_req_grade > 150 || _exec_req_grade > 150) throw Form::GradeTooLowException();
}

std::string Form::getName() const
{
	return name;
}

bool Form::get_is_signed() const
{
	return is_signed;
}

long Form::get_sign_req_grade() const
{
	return sign_req_grade;
}

long Form::get_exec_req_grade() const
{
	return exec_req_grade;
}

void Form::beSigned(Bureaucrat signer)
{
	if (sign_req_grade < signer.getGrade()) throw Form::GradeTooLowException();

	is_signed = true;
}

Form::GradeTooHighException::GradeTooHighException(): std::runtime_error("Form grade too high.") {}
Form::GradeTooLowException::GradeTooLowException(): std::runtime_error("Form grade too low.") {}

std::ostream &operator<<(std::ostream &stream, const Form &in)
{
	std::stringstream ss;
	ss << in.getName() << ", signed: " << in.get_is_signed() << ", sign grade: " << in.get_sign_req_grade() << ", execute grade: " << in.get_exec_req_grade() << ".";
	stream << ss.str();
	return stream;
}

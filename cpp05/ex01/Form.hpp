
#ifndef FORM_HPP
#define FORM_HPP

#include <stdexcept>
#include <string>
#include <sstream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string name;
	bool is_signed;
	const long sign_req_grade;
	const long exec_req_grade;

public:
	Form();
	Form(const Form &src);
	Form &operator=(Form &src);
	~Form();

	Form(std::string name, long sign_req_grade, long exec_req_grade);

	std::string getName() const;
	bool get_is_signed() const;
	long get_sign_req_grade() const;
	long get_exec_req_grade() const;

	void beSigned(Bureaucrat signer);

	class GradeTooHighException: public std::runtime_error
	{
	public:
		GradeTooHighException();
	};

	class GradeTooLowException: public std::runtime_error
	{
	public:
		GradeTooLowException();
	};

};

std::ostream &operator<<(std::ostream &stream, const Form &in);

#endif

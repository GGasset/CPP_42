
#ifndef FORM_HPP
#define FORM_HPP

#include <stdexcept>
#include <string>
#include <sstream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string name;
	bool is_signed;
	const long sign_req_grade;
	const long exec_req_grade;

protected:
	AForm(std::string name, long sign_req_grade, long exec_req_grade);

public:
	AForm();
	AForm(const AForm &src);
	AForm &operator=(AForm &src);
	~AForm();


	std::string getName() const;
	bool get_is_signed() const;
	long get_sign_req_grade() const;
	long get_exec_req_grade() const;

	void beSigned(Bureaucrat signer);
	void execute(Bureaucrat &executor);
	virtual void form_specific_execute(Bureaucrat &executor) = 0;

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

	class FormNotSignedException: public std::runtime_error
	{
	public:
		FormNotSignedException();
	};
};

std::ostream &operator<<(std::ostream &stream, const AForm &in);

#endif

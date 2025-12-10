
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
	const std::string target;

	const std::string name;
	bool is_signed;
	const long sign_req_grade;
	const long exec_req_grade;

protected:
	AForm(std::string name, long sign_req_grade, long exec_req_grade);
	AForm(std::string name, long sign_req_grade, long exec_req_grade, const std::string target);

public:
	AForm();
	AForm(const AForm &src);
	AForm &operator=(AForm &src);
	virtual ~AForm();


	std::string getName() const;
	std::string getTarget() const;
	bool get_is_signed() const;
	long get_sign_req_grade() const;
	long get_exec_req_grade() const;

	void beSigned(Bureaucrat signer);
	void execute(const Bureaucrat &executor) const;
	virtual void form_specific_execute() const = 0;

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

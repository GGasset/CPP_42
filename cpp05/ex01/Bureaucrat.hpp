
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "stdexcept"
#include "string"
#include "sstream"
#include "iostream"

#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	const std::string name; 
	long grade;
	
public:
	Bureaucrat();
	Bureaucrat(const std::string name, long grade);
	Bureaucrat(const Bureaucrat &src);
	Bureaucrat &operator=(const Bureaucrat &src);
	~Bureaucrat();

	Bureaucrat &operator+=(long dgrade);
	Bureaucrat &operator-=(long dgrade);
	
	std::string getName() const;
	long getGrade() const;

	void signForm(Form form);

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

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &in);

#endif

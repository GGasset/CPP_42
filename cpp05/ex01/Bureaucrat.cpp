#include "Bureaucrat.hpp"

Bureaucrat::GradeTooHighException::GradeTooHighException(): std::runtime_error("Bureaucrat grade too high")
{
}

Bureaucrat::GradeTooLowException::GradeTooLowException(): std::runtime_error("Bureaucrat grade too low")
{
}

Bureaucrat::Bureaucrat(): name("unnamed"), grade(150)
{
}

Bureaucrat::Bureaucrat(std::string _name, long grade): name(_name)
{
	this->grade = grade;
	if (grade < 1)		throw GradeTooHighException();
	if (grade > 150)	throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &src): name(src.name), grade(src.grade)
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	grade = src.grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat &Bureaucrat::operator+=(long dgrade)
{
	grade += dgrade;
	if (grade < 1)		throw GradeTooHighException();
	if (grade > 150)	throw GradeTooLowException();
	return *this;
}

Bureaucrat &Bureaucrat::operator-=(long dgrade)
{
	grade -= dgrade;
	if (grade < 1)		throw GradeTooHighException();
	if (grade > 150)	throw GradeTooLowException();
	return *this;
}

std::string Bureaucrat::getName() const
{
	return name;
}

long Bureaucrat::getGrade() const
{
	return grade;
}

void Bureaucrat::signForm(Form form)
{
	try
	{
		form.beSigned(*this);
		std::cout << *this << " signed " << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << *this << " could not sign form " << form << " because " << e.what() << std::endl; 
	}
}

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &in)
{
	std::stringstream ss;

	ss << in.getName() << std::string(", bureaucrat grade ") << in.getGrade() << ".";
	stream << ss.str();

	return stream;
}

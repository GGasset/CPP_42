#include "Ice.hpp"

Ice::Ice()
{
	type = "ice";
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice &src)
{
	std::cout << "Ice copy constructor called" << std::endl;
	*this = src;
}

Ice &Ice::operator=(const Ice &src)
{
	std::cout << "Ice copy assignment called" << std::endl;
	type = src.type;
	return *this;
}

Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
}

AMateria *Ice::clone() const
{
	Ice *out = new Ice(*this);
	return out;
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

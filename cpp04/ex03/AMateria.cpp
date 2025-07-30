#include "AMateria.hpp"

AMateria::AMateria(): type("default type")
{
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type)
{
	this->type = type;
	std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &src)
{
	std::cout << "AMateria copy constructor called. Copy the pointer instead or use clone() method" << std::endl;
	*this = src;
}

AMateria &AMateria::operator=(const AMateria &src)
{
	std::cout << "AMateria assignment operator called, Copy the pointer or use clone() method" << std::endl;
	type = src.type;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
}

std::string const & AMateria::getType() const
{
	return type;
}

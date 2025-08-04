#include "Cure.hpp"

Cure::Cure()
{
	type = "cure";
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure &src)
{
	std::cout << "Cure copy constructor called" << std::endl;
	*this = src;
}

Cure &Cure::operator=(const Cure &src)
{
	type = src.type;
	std::cout << "Cure copy assignment called" << std::endl;
	return *this;
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}

AMateria *Cure::clone() const
{
	Cure *out = new Cure();
	*out = *this;
	return out;
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << " wounds *" << std::endl;
}

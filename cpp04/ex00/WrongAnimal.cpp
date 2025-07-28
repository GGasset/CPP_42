#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("wrong animal")
{
	std::cout << "Wrong animal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	std::cout << "Wrong animal copy constructor called" << std::endl;
	*this = src;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
	std::cout << "Wrong animal assignment operator called" << std::endl;
	type = src.type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Wrong animal destructor called" << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "[A strange sound is heard and ignored coming from the background, it somehow feels wrong ]" << std::endl;
}

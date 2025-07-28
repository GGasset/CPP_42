#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &src)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
}

Dog &Dog::operator=(const Dog &src)
{
	type = src.type;
	std::cout << "Dog assignment operator called" << std::endl;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "[Bark]" << std::endl;
}

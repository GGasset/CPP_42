#include "Animal.hpp"

Animal::Animal(): type("Undiscovered specie")
{
	std::cout << "Default Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &src)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
}

Animal &Animal::operator=(const Animal &src)
{
	std::cout << "Animal assignment operator called" << std::endl;
	type = src.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound()
{
	std::cout << "[Undistinguishible sounds in the background]" << std::endl;
}

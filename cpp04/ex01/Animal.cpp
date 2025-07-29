#include "Animal.hpp"

Animal::Animal(): type("Undiscovered specie")
{
	std::cout << "Default Animal constructor called" << std::endl;

	brain = new Brain();
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
	if (brain && src.brain)
		*brain = *src.brain;

	return *this;
}

Animal::~Animal()
{
	if (brain) delete brain;

	std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const
{
	return type;
}

void Animal::makeSound() const
{
	std::cout << "[Undistinguishible sounds in the background]" << std::endl;
}

Brain *Animal::get_brain()
{
	return brain;
}

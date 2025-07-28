#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "Wrong cat constructor called" << std::endl;
	type = "Wrong cat";
}

WrongCat::WrongCat(const WrongCat &src)
{
	*this = src;
	std::cout << "Wrong cat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &src)
{
	type = src.type;
	std::cout << "Wrong cat copy assignment called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "Wrong cat destructor called" << std::endl;
}

void WrongCat::makeSound()
{
	std::cout << "[ Cat noises can be heard, it somehow feels wrong... ]"
}

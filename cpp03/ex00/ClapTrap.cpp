#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Unnamed"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "Default constructor called!" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Constructor called!" << std::endl;

	*this = ClapTrap();
	this->name = name;
}

ClapTrap::ClapTrap(const ClapTrap &src) : name(src.name), hitPoints(src.hitPoints), energyPoints(src.energyPoints), attackDamage(src.attackDamage)
{
	std::cout << "Copy constructor called!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
	ClapTrap out(src);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called!" << std::endl;
}

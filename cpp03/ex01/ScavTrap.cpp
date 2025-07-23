#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;

	name = "Unnamed";
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "ScavTrap constructor called" << std::endl;

	*this = ScavTrap();
	this->name =  name;
}

ScavTrap::ScavTrap(const ScavTrap &src)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (!energyPoints)
	{
		std::cout << name << " tried attacking like a good ScavTrap, but he cannot calculate its energy properly, " << name << " can do it better >:(" << std::endl;
		return;
	}
	else if (hitPoints <= 0)
	{
		std::cout << name << " was dead, it turns out that this ScavTrap is not suited to attack " << target << " I'll get another one instead >:(" << std::endl;
		return;
	}

	energyPoints--;
	std::cout << name << " has attacked " << target << ", " << target << " lost " << attackDamage << " points! Nice done ScavTrap! :)" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}

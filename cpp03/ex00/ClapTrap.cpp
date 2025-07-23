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

ClapTrap::ClapTrap(const ClapTrap &src)
{
	std::cout << "Copy constructor called!" << std::endl;
	*this = src;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
	std::cout << "Copy assignment called!" << std::endl;

	name = src.name;
	hitPoints = src.hitPoints;
	energyPoints = src.energyPoints;
	attackDamage = src.attackDamage;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called!" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (!energyPoints)
	{
		std::cout << name << " tried attacking but " << name << " doesn't have energy and temporarily suffocated instead ;((" << std::endl;
		return;
	}
	else if (hitPoints <= 0)
	{
		std::cout << name << " was dead, however it continued trying to attack " << target << ", his malfunctioning cpu decided he wanted world domination, the cpu burned succesfully." << std::endl;
		return;
	}

	energyPoints--;
	std::cout << name << " has attacked " << target << ", " << target << " lost " << attackDamage << " points!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints <= 0)
	{
		std::cout << "Someone attacked " << name << " even though he was dead, gross :(" << std::endl;
		return;
	}

	std::cout << name << " had " << hitPoints << " of health, but got attacked, causing " << amount << " damage ";

	hitPoints -= amount;
	if (hitPoints <= 0)
		std::cout << name << " died." << std::endl;
	else
		std::cout << name << " is left with " << hitPoints << " health." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints <= 0)
	{
		std::cout << "Even though he was dead " << name << " tried repairing itself, he successfully broke its arm and drained its batery completely." << std::endl;
		return;
	}
	std::cout << name << " tried reparing itself, having " << hitPoints << " health";
	if (energyPoints <= 0)
		std::cout << " but didn't have any energy left, it soldered itself to the ground instead :((" << std::endl;
	else
	{
		energyPoints--;
		hitPoints += amount;
		std::cout << " he succesfully repaired himself and was left with " << hitPoints << " health." << std::endl;
	}
}

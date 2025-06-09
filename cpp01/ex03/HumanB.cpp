
#include "HumanB.hpp"

HumanB::HumanB(): name("default"), weapon(0)
{
}

HumanB::HumanB(std::string _name) : name(_name), weapon(0)
{
}

HumanB::~HumanB()
{
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon; 
}

void HumanB::attack()
{
	if (!weapon)
	{
		std::cout << name << " tried to attack but lacks a weapon and thus is unable to." << std::endl;
		return;
	}
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

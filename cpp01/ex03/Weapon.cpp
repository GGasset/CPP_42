
#include "Weapon.hpp"

Weapon::Weapon(std::string _type): type(_type)
{
}

Weapon::~Weapon()
{
}

const std::string &Weapon::getType()
{
	return type;
}

void Weapon::setType(std::string type)
{
	this->type = type;
}

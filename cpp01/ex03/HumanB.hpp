
#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB
{
private:
	std::string name;
	Weapon *weapon;

public:
	HumanB();
	HumanB(std::string _name);
	~HumanB();

	void attack();

	void setWeapon(Weapon &weapon);
};



#endif

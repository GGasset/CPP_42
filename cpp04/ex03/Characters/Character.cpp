#include "Character.hpp"

Character::Character()
{
	std::cout << "Character default constructor called" << std::endl;
	std::memset(inventory, 0, sizeof(AMateria *) * inventory_size);
	name = "Unknown";
}

Character::Character(const std::string name)
{
	std::cout << "Character constructor called" << std::endl;
	*this = Character();
	this->name = name; 
}

Character::Character(const Character &src)
{
	std::cout << "Character copy constructor called" << std::endl;
	*this = src;
}

Character &Character::operator=(const Character &src)
{
	std::cout << "Character copy assignment called" << std::endl;
	name = src.name;
	for (size_t i = 0; i < inventory_size; i++)
	{
		delete inventory[i];
		inventory[i] = 0;

		if (src.inventory[i]) inventory[i] = src.inventory[i]->clone();
	}
}

Character::~Character()
{
	std::cout << "Character destructor called" << std::endl;
	for (size_t i = 0; i < inventory_size; i++)
	{
		delete inventory[i];
	}
}

std::string const &Character::getName() const
{
	return name;
}

void Character::equip(AMateria *m)
{
	for (size_t i = 0; i < inventory_size; i++)
		if (!inventory[i])
		{
			inventory[i] = m;
			return;
		}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= inventory_size) return;
	inventory[idx] = 0;
}

void Character::unequip_delete(int idx)
{
	AMateria *to_unequip = getMateria(idx);
	unequip(idx);
	delete to_unequip;
}

AMateria *Character::getMateria(int idx)
{
	if (idx < 0 || idx >= inventory_size) return;
	return inventory[idx];
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= inventory_size) return;
	if (!inventory[idx]) return;

	inventory[idx]->use(target);
}

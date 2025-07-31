
#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "cstring"

class Character : ICharacter
{
protected:
	static const size_t inventory_size = 4;
	AMateria *inventory[Character::inventory_size];

public:
	Character();
	Character(const std::string name);
	Character(const Character &src);
	Character &operator=(const Character &src);
	~Character();

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void unequip_delete(int idx);
	AMateria *getMateria(int idx);
	void use(int idx, ICharacter& target);
};

#endif


#ifndef CURE_HPP
# define CURE_HPP

#include "iostream"
#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure();
	Cure(const Cure &src);
	Cure &operator=(const Cure &src);
	~Cure();

	AMateria *clone() const;
	void use(ICharacter& target);
};

#endif

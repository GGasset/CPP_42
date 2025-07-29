
#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include "iostream"

#include "Brain.hpp"

class Animal
{
protected:
	std::string type;

	Brain *brain;

public:
	Animal();
	Animal(const Animal &src);
	Animal &operator=(const Animal &src);
	virtual ~Animal();

	std::string getType() const;
	virtual void makeSound() const;

	Brain *get_brain();
};

#endif

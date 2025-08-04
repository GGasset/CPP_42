#include "Ice.hpp"
#include "Cure.hpp"

#include "MateriaSource.hpp"
#include "Character.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(0);
	
	ICharacter* me = new Character("me");
	
	std::cout << std::endl;
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	std::cout << std::endl;
	tmp = src->createMateria("cure");
	me->equip(tmp);
	std::cout << std::endl;

	ICharacter* bob = new Character("bob");

	std::cout << std::endl;

	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << std::endl;

	me->unequip_delete(1);
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(-1, *bob);
	me->use(8, *bob);
	me->unequip_delete(800);
	me->unequip_delete(-3);
	me->unequip_delete(1);

	std::cout << std::endl;

	delete bob;
	delete me;
	delete src;
	
	return 0;
}


#include "iostream"

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	WrongAnimal* wrong_cat = new WrongCat();
	wrong_cat->makeSound();
	std::cout << wrong_cat->getType() << std::endl;
	delete wrong_cat;

	return 0;
}

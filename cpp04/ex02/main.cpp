
#include "iostream"

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const size_t animal_n = 100;
	
	Animal **animals = new Animal*[animal_n];
	for (size_t i = 0; i < animal_n; i++)
		if (i < animal_n / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();

	Animal *copy_test = new Dog();
	std::cout << "Idea 0 before copy " << copy_test->get_brain()->get_idea(0) << std::endl;
	
	Animal *tmp = animals[20];
	tmp->get_brain()->set_idea(0, "Monkey climb tree, monkey no taxes, mokey free.");
	
	*copy_test = *tmp;
	std::cout << "Idea 0 after copy " << copy_test->get_brain()->get_idea(0) << std::endl;

	for (size_t i = 0; i < animal_n; i++)
		delete animals[i];
	delete[] animals;
	

	return 0;
}

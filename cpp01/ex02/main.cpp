
#include "iostream"
#include "string"

int main()
{
	std::string brain = "HI THIS IS BRAIN";
	std::string *brain_pntr = &brain;
	std::string &brain_ref = brain;

	std::cout << "Memory address of string: " << &brain << std::endl;
	std::cout << "Memory address held by string_pntr: " << brain_pntr << std::endl;
	std::cout << "Memory address held by string_ref: " << &brain_ref << std::endl;

	std::cout << "Value of string: " << brain << std::endl;
	std::cout << "Value pointed by string_pntr: " << *brain_pntr << std::endl;
	std::cout << "Value pointed by string_ref: " << brain_ref << std::endl;

}

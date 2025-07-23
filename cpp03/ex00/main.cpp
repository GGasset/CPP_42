#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap energy_defficient("Energy defficient ClapTrap");
	for (size_t i = 0; i < 6; i++)
	{
		energy_defficient.attack("Imaginary target");
		energy_defficient.beRepaired(1);
		energy_defficient.takeDamage(1);
		std::cout << std::endl;
	}
	std::cout << std::endl;

	ClapTrap dead("Clap Trap about to die");
	for (size_t i = 0; i < 6; i++)
	{
		dead.takeDamage(3);
		dead.attack("Practice target");
		dead.beRepaired(1);
		std::cout << std::endl;
	}
	
}
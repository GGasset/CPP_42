#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap energy_defficient("Energy defficient ScavTrap");
	for (size_t i = 0; i < 51; i++)
	{
		energy_defficient.attack("Imaginary target");
	}
	energy_defficient.beRepaired(1);
	energy_defficient.takeDamage(1);
	std::cout << std::endl;
	std::cout << std::endl;

	ScavTrap dead("ScavTrap about to die");
	for (size_t i = 0; i < 6; i++)
	{
		dead.takeDamage(21);
		dead.attack("Practice target");
		dead.beRepaired(1);
		std::cout << std::endl;
	}
}
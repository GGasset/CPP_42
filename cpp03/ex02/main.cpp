#include "FragTrap.hpp"

int main(void)
{
	FragTrap energy_defficient("Energy defficient FragTrap");
	for (size_t i = 0; i < 101; i++)
	{
		energy_defficient.attack("Imaginary target");
	}
	energy_defficient.beRepaired(1);
	energy_defficient.takeDamage(1);
	std::cout << std::endl;
	std::cout << std::endl;

	FragTrap dead("FragTrap about to die");
	for (size_t i = 0; i < 6; i++)
	{
		dead.takeDamage(26);
		dead.attack("Practice target");
		dead.beRepaired(1);
		std::cout << std::endl;
	}
}
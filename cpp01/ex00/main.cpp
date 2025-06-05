
#include "Zombie.hpp"

int main()
{
	std::cout << "Random chump:" << std::endl;
	randomChump("Juan");

	std::cout << std::endl << "New zombie:" << std::endl;
	Zombie *zombie = newZombie("Paco");
	zombie->announce();
	delete zombie;
}

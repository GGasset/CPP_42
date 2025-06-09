
#include "Zombie.hpp"

int main()
{
	std::cout << "Random chump:" << std::endl;
	randomChump("Mi primo Juan");

	std::cout << std::endl << "New zombie:" << std::endl;
	Zombie *zombie = newZombie("Mi tio Paco");
	zombie->announce();
	delete zombie;
}

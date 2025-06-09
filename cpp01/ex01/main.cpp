
#include "Zombie.hpp"

int main()
{
	size_t paco_count = 300;
	Zombie *horde = zombieHorde(paco_count, "Los comunistas y unidos 300s Pacos");
	for (size_t i = 0; horde && i < paco_count; i++)
	{
		horde[i].announce();
	}
	delete[] horde;
}

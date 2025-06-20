
#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *horde = new Zombie[N];
	for (size_t i = 0; horde && (int)i < N; i++)
	{
		horde[i] = Zombie(name);
	}
	return horde;
}

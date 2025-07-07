#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	if (N <= 0 || name.empty())
	{
		std::cerr << "Invalid parameters for zombie horde." << std::endl;
		return 0;
	}
	Zombie *horde = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		horde[i].setName(name);
		horde[i].announce();
	}
	return horde;
}

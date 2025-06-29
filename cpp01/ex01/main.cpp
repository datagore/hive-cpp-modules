#include "Zombie.hpp"

int main()
{
	const int numZombies = 5;
	Zombie* horde = zombieHorde(numZombies, "Bob");
	for (int i = 0; i < numZombies; i++)
		horde[i].announce();
	delete[] horde;
}

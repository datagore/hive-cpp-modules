#include "Zombie.hpp"

int main()
{
	Zombie* alice = newZombie("Alice");
	alice->announce();
	randomChump("Bob");
	randomChump("Charlie");
	delete alice;
}

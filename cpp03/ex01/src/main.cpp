#include "ScavTrap.hpp"

int main()
{
	ScavTrap alice("Alice");
	ScavTrap bob("Bob");
	alice.attack("Charlie");
	alice.guardGate();
}

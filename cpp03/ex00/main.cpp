#include "ClapTrap.hpp"

int main()
{
	ClapTrap alice("Alice");
	ClapTrap bob("Bob");
	ClapTrap bobClone(bob);
	for (int i = 0; i < 12; i++) {
		alice.attack("Bob");
		bob.beRepaired(1);
	}
	bob.takeDamage(8);
	bob.takeDamage(8);
	bob.takeDamage(8);
}

#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap monster("Monster");
	monster.attack("Charlie"); // ClapTrap method.
	monster.guardGate(); // ScavTrap method.
	monster.highFivesGuys(); // FragTrap method.
	monster.whoAmI(); // DiamondTrap method.
	for (int i = 0; i < 4; i++) {
		monster.takeDamage(33);
		monster.attack("Bob");
	}
}

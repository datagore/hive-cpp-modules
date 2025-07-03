#include <iostream>

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name)
	: ClapTrap(name, 100, 100, 30)
{
	std::cout << "FragTrap " << name << " appears out of nowhere\n";
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " disappears into thin air\n";
}

FragTrap::FragTrap(const FragTrap& f)
	: ClapTrap(f.name, f.hitPoints, f.energyPoints, f.attackDamage)
{
	std::cout << "A clone of FragTrap " << name << " appears\n";
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this != &other) {
		std::cout << "FragTrap " << name << " turns into a clone of ";
		std::cout << other.name << "\n";
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	return *this;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << name << " requests high fives\n";
}

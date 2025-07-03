#include <iostream>

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string& name)
	: ClapTrap(name + "_clap_name", 100, 50, 30),
	  FragTrap(name + "_clap_name"),
	  ScavTrap(name + "_clap_name"),
	  name(name)
{
	std::cout << "DiamondTrap " << name << " appears out of nowhere\n";
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << name << " disappears into thin air\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& d)
	: ClapTrap(d.name + "_clap_name", d.hitPoints, d.energyPoints, d.attackDamage),
	  FragTrap(d.name + "_clap_name"),
	  ScavTrap(d.name + "_clap_name"),
	  name(d.name)
{
	std::cout << "A clone of DiamondTrap " << name << " appears\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other) {
		std::cout << "DiamondTrap " << name << " turns into a clone of ";
		std::cout << other.name << "\n";
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	return *this;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "My DiamondTrap name is " << name << " and my ClapTrap name ";
	std::cout << "is " << ClapTrap::name << "\n";
}

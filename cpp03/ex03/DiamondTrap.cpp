#include <iostream>

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
	: DiamondTrap("DiamondTrap")
{
}

DiamondTrap::DiamondTrap(const std::string& name)
	: ClapTrap(name + "_clap_name", 100, 50, 30),
	  ScavTrap(ClapTrap::name),
	  FragTrap(ClapTrap::name),
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
	  ScavTrap(ClapTrap::name),
	  FragTrap(ClapTrap::name),
	  name(d.name)
{
	std::cout << "A clone of DiamondTrap " << name << " appears\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other) {
		ClapTrap::operator=(other);
		std::cout << "DiamondTrap " << name << " turns into a clone of ";
		std::cout << other.name << "\n";
		name = other.name;
	}
	return *this;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap " << name << "'s ClapTrap name is ";
	std::cout << ClapTrap::name << "\n";
}

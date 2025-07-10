#include <iostream>

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
	: DiamondTrap("DiamondTrap")
{
}

DiamondTrap::DiamondTrap(const std::string& name)
	: ClapTrap(name + "_clap_name"),
	  FragTrap(ClapTrap::name),
	  ScavTrap(ClapTrap::name),
	  name(name)
{
	hitPoints = FragTrap::hitPoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;
	std::cout << "DiamondTrap " << name << " appears out of nowhere\n";
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << name << " disappears into thin air\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& d)
	: ClapTrap(d.name + "_clap_name", d.hitPoints, d.energyPoints, d.attackDamage),
	  FragTrap(ClapTrap::name),
	  ScavTrap(ClapTrap::name),
	  name(d.name)
{
	std::cout << "A clone of DiamondTrap " << name << " appears\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other) {
		ClapTrap::operator=(other);
		ScavTrap::operator=(other);
		FragTrap::operator=(other);
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
	std::cout << "DiamondTrap " << name << "'s ClapTrap name is ";
	std::cout << ClapTrap::name << "\n";
}

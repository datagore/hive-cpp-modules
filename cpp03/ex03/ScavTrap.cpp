#include <iostream>

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name)
	: ClapTrap(name, 100, 50, 20)
{
	std::cout << "ScavTrap " << name << " appears out of nowhere\n";
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " disappears into thin air\n";
}

ScavTrap::ScavTrap(const ScavTrap& s)
	: ClapTrap(s.name, s.hitPoints, s.energyPoints, s.attackDamage)
{
	std::cout << "A clone of ScavTrap " << name << " appears\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other) {
		std::cout << "ScavTrap " << name << " turns into a clone of ";
		std::cout << other.name << "\n";
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	return *this;
}

void ScavTrap::attack(const std::string& target)
{
	if (energyPoints == 0) {
		std::cout << "ScavTrap " << name << " has no energy to attack ";
		std::cout << target << "\n";
	} else {
		energyPoints--;
		std::cout << "ScavTrap " << name << " attacks " << target;
		std::cout << ", inflicting " << attackDamage << " points of damage\n";
	}
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is now in gate keeper mode\n";
}

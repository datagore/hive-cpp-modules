#include <iostream>

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name)
	: name(name),
	  hitPoints(10),
	  energyPoints(10),
	  attackDamage(0)
{
	std::cout << name << " appars out of nowhere\n";
}

ClapTrap::~ClapTrap()
{
	std::cout << name << " disappears into thin air\n";
}

ClapTrap::ClapTrap(const ClapTrap& other)
	: name(other.name),
	  hitPoints(other.hitPoints),
	  energyPoints(other.energyPoints),
	  attackDamage(other.attackDamage)
{
	std::cout << "A clone of " << name << " appears out of nowhere\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other) {
		std::cout << name << " turns into a clone of " << other.name << "\n";
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (energyPoints == 0) {
		std::cout << name << " has no energy to attack " << target << "\n";
	} else {
		energyPoints--;
		std::cout << name << " attacks " << target << ", inflicting ";
		std::cout << attackDamage << " points of damage\n";
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	hitPoints = hitPoints < amount ? 0 : hitPoints - amount;
	std::cout << name << " takes " << amount << " points of damage, bringing ";
	std::cout << "their hit points down to " << hitPoints << "\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoints == 0) {
		std::cout << name << " has no energy to repair itself\n";
	} else {
		energyPoints--;
		hitPoints += amount;
		std::cout << name << " is repaired for " << amount << " points, ";
		std::cout << "bringing their hit points up to " << hitPoints << "\n";
	}
}

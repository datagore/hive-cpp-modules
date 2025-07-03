#include <iostream>

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name)
	: name(name),
	  hitPoints(10),
	  energyPoints(10),
	  attackDamage(0)
{
	std::cout << "ClapTrap " << name << " appars out of nowhere\n";
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " disappears into thin air\n";
}

ClapTrap::ClapTrap(const ClapTrap& other)
	: name(other.name),
	  hitPoints(other.hitPoints),
	  energyPoints(other.energyPoints),
	  attackDamage(other.attackDamage)
{
	std::cout << "A clone of ClapTrap " << name << " appears out of nowhere\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other) {
		std::cout << "ClapTrap " << name << " turns into a clone of ";
		std::cout << other.name << "\n";
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
		std::cout << "ClapTrap " << name << " has no energy to attack ";
		std::cout << target << "\n";
	} else {
		energyPoints--;
		std::cout << "ClapTrap " << name << " attacks " << target;
		std::cout << ", inflicting " << attackDamage << " points of damage\n";
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	hitPoints = hitPoints < amount ? 0 : hitPoints - amount;
	std::cout << "ClapTrap " << name << " takes " << amount << " points of ";
	std::cout << "damage\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoints == 0) {
		std::cout << "ClapTrap " << name << " has no energy to repair itself\n";
	} else {
		energyPoints--;
		hitPoints += amount;
		std::cout << "ClapTrap " << name << " is repaired for " << amount;
		std::cout << " points\n";
	}
}

ClapTrap::ClapTrap(const std::string& name, unsigned int hitPoints,
				   unsigned int energyPoints, unsigned int attackDamage)
	: name(name),
	  hitPoints(hitPoints),
	  energyPoints(energyPoints),
	  attackDamage(attackDamage)
{
	std::cout << "ClapTrap " << name << " appars out of nowhere\n";
}

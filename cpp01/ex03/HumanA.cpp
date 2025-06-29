#include <iostream>

#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& weapon)
	: name(name),
	  weapon(weapon)
{
}

HumanA::~HumanA()
{
}

HumanA::HumanA(const HumanA& other)
	: name(other.name),
	  weapon(other.weapon)
{
}

HumanA& HumanA::operator=(const HumanA& other)
{
	if (this != &other) {
		name = other.name;
		weapon = other.weapon;
	}
	return *this;
}

void HumanA::attack()
{
	std::cout << name << " attacks with their " << weapon.getType() << "\n";
}

#include <iostream>

#include "HumanB.hpp"

HumanB::HumanB(const std::string& name)
	: name(name),
	  weapon(nullptr)
{
}

HumanB::~HumanB()
{
}

HumanB::HumanB(const HumanB& other)
	: name(other.name),
	  weapon(other.weapon)
{
}

HumanB& HumanB::operator=(const HumanB& other)
{
	if (this != &other) {
		name = other.name;
		weapon = other.weapon;
	}
	return *this;
}

void HumanB::setWeapon(const Weapon& newWeapon)
{
	weapon = &newWeapon;
}

void HumanB::attack()
{
	std::cout << name << " attacks with their ";
	if (weapon != nullptr)
		std::cout << weapon->getType() << std::endl;
	else
		std::cout << " bare hands";
}

#include <iostream>

#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::Zombie(const std::string& name)
	: name(name)
{
}

Zombie::Zombie(const Zombie& other)
	: name(other.name)
{
}

Zombie& Zombie::operator=(const Zombie& other)
{
	if (this != &other) {
		name = other.name;
	}
	return *this;
}

Zombie::~Zombie()
{
	std::cout << name << ": I'm outta here!\n";
}

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

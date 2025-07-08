#include <iostream>

#include "AMateria.hpp"

AMateria::AMateria(const std::string& type)
	: type(type)
{
	std::cout << "AMateria constructor with type " << type << "\n";
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor with type " << type << "\n";
}

AMateria::AMateria(const AMateria& other)
	: type(other.type)
{
	std::cout << "AMateria copy constructor with type " << type << "\n";
}

AMateria& AMateria::operator=(const AMateria& other)
{
	if (this != &other) {
		type = other.type;
		std::cout << "AMateria copy assignment with type " << type << "\n";
	}
	return *this;
}

const std::string& AMateria::getType() const
{
	return type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "AMateria used on character " << target.getName() << "\n";
}

AMateria::AMateria()
{
}

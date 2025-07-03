#include <iostream>

#include "Cure.hpp"

Cure::Cure()
	: AMateria("cure")
{
	std::cout << "Cure constructor\n";
}

Cure::~Cure()
{
	std::cout << "Cure destructor\n";
}

Cure::Cure(const Cure&)
	: AMateria("cure")
{
	std::cout << "Cure copy constructor\n";
}

Cure& Cure::operator=(const Cure& other)
{
	if (this != &other) {
		std::cout << "Cure copy assignment\n";
	}
	return *this;
}

AMateria* Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}

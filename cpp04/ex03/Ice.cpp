#include <iostream>

#include "Ice.hpp"

Ice::Ice()
	: AMateria("ice")
{
	std::cout << "Ice constructor\n";
}

Ice::~Ice()
{
	std::cout << "Ice destructor\n";
}

Ice::Ice(const Ice&)
	: AMateria("ice")
{
	std::cout << "Ice copy constructor\n";
}

Ice& Ice::operator=(const Ice& other)
{
	if (this != &other) {
		std::cout << "Ice copy assignment\n";
	}
	return *this;
}

AMateria* Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}

#include <iostream>

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal constructor\n";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
	: type(other.type)
{
	std::cout << "WrongAnimal copy constructor\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other) {
		std::cout << "WrongAnimal copy assignment\n";
		type = other.type;
	}
	return *this;
}

void WrongAnimal::makeSound() const
{
	std::cout << "*WrongAnimal noises*\n";
}

const std::string& WrongAnimal::getType() const
{
	return type;
}

WrongAnimal::WrongAnimal(const std::string& type)
	: type(type)
{
	std::cout << "WrongAnimal constructor with type " << type << "\n";
}

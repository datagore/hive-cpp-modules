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

WrongAnimal::WrongAnimal(const WrongAnimal&)
{
	std::cout << "WrongAnimal copy constructor\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other) {
		std::cout << "WrongAnimal copy assignment\n";
	}
	return *this;
}

void WrongAnimal::makeSound()
{
	std::cout << "*Record scratch*\n";
}

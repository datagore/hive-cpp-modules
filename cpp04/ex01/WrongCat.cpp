#include <iostream>

#include "WrongCat.hpp"

WrongCat::WrongCat()
	: WrongAnimal("WrongCat")
{
	std::cout << "WrongCat constructor\n";
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor\n";
}

WrongCat::WrongCat(const WrongCat& other)
	: WrongAnimal(other.type)
{
	std::cout << "WrongCat copy constructor\n";
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	if (this != &other) {
		std::cout << "WrongCat copy assignment\n";
		type = other.type;
	}
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat Meow!\n";
}

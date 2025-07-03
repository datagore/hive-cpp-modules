#include <iostream>

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat constructor\n";
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor\n";
}

WrongCat::WrongCat(const WrongCat&)
{
	std::cout << "WrongCat copy constructor\n";
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	if (this != &other)
		std::cout << "WrongCat copy assignment\n";
	return *this;
}

void WrongCat::makeSound()
{
	std::cout << "*Air horn sounds*\n";
}

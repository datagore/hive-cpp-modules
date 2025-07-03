#include <iostream>

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal constructor\n";
}

Animal::~Animal()
{
	std::cout << "Animal destructor\n";
}

Animal::Animal(const Animal& other)
	: type(other.type)
{
	std::cout << "Animal copy constructor\n";
}

Animal& Animal::operator=(const Animal& other)
{
	if (this != &other) {
		std::cout << "Animal copy assignment\n";
		type = other.type;
	}
	return *this;
}

const std::string& Animal::getType() const
{
	return type;
}

Animal::Animal(const std::string& type)
	: type(type)
{
	std::cout << "Animal constructor with type " << type << "\n";
}

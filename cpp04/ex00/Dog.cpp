#include <iostream>

#include "Dog.hpp"

Dog::Dog()
	: Animal("Dog")
{
	std::cout << "Dog constructor\n";
}

Dog::~Dog()
{
	std::cout << "Dog destructor\n";
}

Dog::Dog(const Dog& other)
	: Animal(other.type)
{
	std::cout << "Dog copy constructor\n";
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other) {
		std::cout << "Dog copy assignment\n";
		type = other.type;
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Woof!\n";
}

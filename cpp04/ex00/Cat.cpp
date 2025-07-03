#include <iostream>

#include "Cat.hpp"

Cat::Cat()
	: Animal("Cat")
{
	std::cout << "Cat constructor\n";
}

Cat::~Cat()
{
	std::cout << "Cat destructor\n";
}

Cat::Cat(const Cat& other)
	: Animal(other.type)
{
	std::cout << "Cat copy constructor\n";
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other) {
		std::cout << "Cat copy assignment\n";
		type = other.type;
	}
	return *this;
}

void Cat::makeSound()
{
	std::cout << "Meow!\n";
}

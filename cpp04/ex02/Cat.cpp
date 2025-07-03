#include <iostream>

#include "Cat.hpp"

Cat::Cat()
	: Animal("Cat"),
	  brain(new Brain())
{
	std::cout << "Cat constructor\n";
	for (int i = 0; i < Brain::NUM_THOUGHTS; i++)
		brain->setThought(i, "CAT TREATS");
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat destructor\n";
}

Cat::Cat(const Cat& other)
	: Animal(other.type),
	  brain(new Brain(*other.brain))
{
	std::cout << "Cat copy constructor\n";
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other) {
		std::cout << "Cat copy assignment\n";
		type = other.type;
		*brain = *other.brain;
	}
	return *this;
}

void Cat::makeSound()
{
	std::cout << "Meow!\n";
}

Brain& Cat::getBrain()
{
	return *brain;
}

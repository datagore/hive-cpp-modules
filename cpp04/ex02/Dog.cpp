#include <iostream>

#include "Dog.hpp"

Dog::Dog()
	: Animal("Dog"),
	  brain(new Brain())
{
	std::cout << "Dog constructor\n";
	for (int i = 0; i < Brain::NUM_THOUGHTS; i++)
		brain->setThought(i, "DOG TREATS");
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog destructor\n";
}

Dog::Dog(const Dog& other)
	: Animal(other.type),
	  brain(new Brain(*other.brain))
{
	std::cout << "Dog copy constructor\n";
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other) {
		std::cout << "Dog copy assignment\n";
		type = other.type;
		*brain = *other.brain;
	}
	return *this;
}

void Dog::makeSound()
{
	std::cout << "Woof!\n";
}

Brain& Dog::getBrain()
{
	return *brain;
}

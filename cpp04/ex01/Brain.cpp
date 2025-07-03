#include <iostream>

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor\n";
}

Brain::~Brain()
{
	std::cout << "Brain destructor\n";
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain copy constructor\n";
	for (int i = 0; i < NUM_THOUGHTS; i++)
		thoughts[i] = other.thoughts[i];
}

Brain& Brain::operator=(const Brain& other)
{
	if (this != &other) {
		std::cout << "Brain copy assignment\n";
		for (int i = 0; i < NUM_THOUGHTS; i++)
			thoughts[i] = other.thoughts[i];
	}
	return *this;
}

const std::string& Brain::getThought(int index) const
{
	return thoughts[index];
}

void Brain::setThought(int index, const std::string& thought)
{
	thoughts[index] = thought;
}

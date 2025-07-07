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
	for (int i = 0; i < NUM_IDEAS; i++)
		ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain& other)
{
	if (this != &other) {
		std::cout << "Brain copy assignment\n";
		for (int i = 0; i < NUM_IDEAS; i++)
			ideas[i] = other.ideas[i];
	}
	return *this;
}

std::string Brain::getIdea(int index) const
{
	if (index < 0 || index >= NUM_IDEAS)
		return "";
	return ideas[index];
}

void Brain::setIdea(int index, const std::string& idea)
{
	if (0 <= index && index < NUM_IDEAS)
		ideas[index] = idea;
}

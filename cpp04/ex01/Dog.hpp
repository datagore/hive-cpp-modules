#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
public:
	Dog();
	~Dog();
	Dog(const Dog& other);
	Dog& operator=(const Dog& other);
	void makeSound();
	Brain& getBrain();

private:
	Brain* brain;
};

#endif // #ifndef DOG_HPP

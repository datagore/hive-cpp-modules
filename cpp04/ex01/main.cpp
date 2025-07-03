#include <iostream>

#include "Cat.hpp"
#include "Dog.hpp"

void testArray()
{
	std::cout << "===== Array test =====\n";
	Animal *animals[6];
	for (int i = 0; i < 3; i++)
		animals[i] = new Dog();
	for (int i = 3; i < 6; i++)
		animals[i] = new Cat();
	for (int i = 0; i < 6; i++)
		delete animals[i];
}

void testDeepCopy()
{
	std::cout << "\n===== Deep copy test =====\n";
	Dog firstDog;
	Dog secondDog = firstDog;
	firstDog.getBrain().setThought(0, "CHASING CARS");
	std::cout << firstDog.getBrain().getThought(0) << std::endl;
	std::cout << secondDog.getBrain().getThought(0) << std::endl;
}

int main()
{
	testArray();
	testDeepCopy();
}

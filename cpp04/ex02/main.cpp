#include <iostream>

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	try {
		// Animal animal; // Can't be uncommented because Animal is abstract.
		Cat cat; // Works fine.
		Dog dog; // Works fine.
	} catch (std::exception& exception) {
		std::cout << exception.what() << std::endl;
	}
}

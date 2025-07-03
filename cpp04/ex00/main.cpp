#include <iostream>

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void testAnimals()
{
	std::cout << "===== Animal tests =====\n";
	Dog dog;
	Cat cat;
	Animal& catAnimal = cat;
	Animal& dogAnimal = dog;
	cat.makeSound();
	dog.makeSound();
	catAnimal.makeSound();
	dogAnimal.makeSound();
	std::cout << "dogAnimal type: " << dogAnimal.getType() << "\n";
	std::cout << "catAnimal type: " << catAnimal.getType() << "\n";
}

void testWrongCat()
{
	std::cout << "\n===== WrongCat tests =====\n";
	WrongCat wrongCat;
	WrongAnimal& wrongAnimal = wrongCat;
	wrongCat.makeSound();
	wrongAnimal.makeSound();
}

int main()
{
	testAnimals();
	testWrongCat();
}

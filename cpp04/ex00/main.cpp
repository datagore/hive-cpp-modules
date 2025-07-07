#include <iostream>

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void testAnimals()
{
	std::cout << "===== Animal tests =====\n";
	Animal *animal = new Animal();
	Dog* dog = new Dog();
	Cat* cat = new Cat();
	animal->makeSound();
	dog->makeSound();
	cat->makeSound();
	std::cout << "dog type: " << dog->getType() << "\n";
	std::cout << "cat type: " << cat->getType() << "\n";
	delete animal;
	delete dog;
	delete cat;
}

void testWrongCat()
{
	std::cout << "\n===== WrongCat tests =====\n";
	WrongAnimal *wrongCat = new WrongCat();
	wrongCat->makeSound();
	delete wrongCat;
}

int main()
{
	try {
		testAnimals();
		testWrongCat();
	} catch (std::exception& exception) {
		std::cout << exception.what() << std::endl;
	}
}

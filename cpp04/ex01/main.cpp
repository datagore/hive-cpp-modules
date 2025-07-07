#include <iostream>

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void arrayTest()
{
	std::cout << "===== ARRAY TEST =====\n";
	Animal* animals[6];
	for (int i = 0; i < 3; i++)
		animals[i] = new Dog();
	for (int i = 3; i < 6; i++)
		animals[i] = new Cat();
	for (int i = 0; i < 6; i++)
		delete animals[i];
}

void deepCopyTest()
{
	std::cout << "\n===== ARRAY TEST =====\n";
	Dog dog1;
	Dog dog2(dog1);
	dog1.getBrain().setIdea(0, "CHASING CARS");
	std::cout << "dog1 is thinking of " << dog1.getBrain().getIdea(0) << "\n";
	std::cout << "dog2 is thinking of " << dog2.getBrain().getIdea(0) << "\n";
}

int main()
{
	try {
		arrayTest();
		deepCopyTest();
	} catch (std::exception& exception) {
		std::cout << exception.what() << std::endl;
	}
}

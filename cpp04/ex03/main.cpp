#include <iostream>

#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

void runTests()
{
	std::cout << "\n===== MATERIA SOURCE CREATION =====\n";
	IMateriaSource* materiaSource = new MateriaSource();
	materiaSource->learnMateria(new Ice());
	materiaSource->learnMateria(new Cure());
	materiaSource->learnMateria(nullptr); // Not a real materia.

	std::cout << "\n===== CHARACTER CREATION =====\n";
	ICharacter* character = new Character("Bob");
	character->equip(materiaSource->createMateria("ice"));
	character->equip(materiaSource->createMateria("cure"));
	character->equip(materiaSource->createMateria("fire")); // No such spell.

	std::cout << "\n===== SPELL CASTING TESTS =====\n";
	character->use(0, *character);
	character->use(1, *character);
	character->use(2, *character); // Unused materia slot.
	character->use(-1, *character); // Invalid slot number.

	std::cout << "\n===== INVENTORY OVERFLOW TEST =====\n";
	for (int i = 0; i < 5; i++) // Add too many materias.
		character->equip(materiaSource->createMateria("ice"));

	std::cout << "\n===== MATERIA SOURCE OVERFLOW TEST =====\n";
	for (int i = 0; i < 5; i++) // Learn too many materias.
		materiaSource->learnMateria(new Cure());

	std::cout << "\n===== CHARACTER DESTRUCTION =====\n";
	delete character;

	std::cout << "\n===== MATERIA SOURCE DESTRUCTION =====\n";
	delete materiaSource;
	std::cout << "\n";
}

int main()
{
	try {
		runTests();
	} catch (std::exception& exception) {
		std::cout << exception.what() << std::endl;
	}
}

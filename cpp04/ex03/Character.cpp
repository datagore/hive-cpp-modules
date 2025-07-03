#include <iostream>

#include "Character.hpp"

Character::Character(const std::string& name)
	: name(name)
{
	std::cout << "Constructor for Character " << name << "\n";
	for (int i = 0; i < NUM_MATERIA_SLOTS; i++)
		equipped[i] = nullptr;
}

Character::~Character()
{
	std::cout << "Destructor for Character " << name << "\n";
}

Character::Character(const Character& other)
	name(other.name)
{
	std::cout << "Copy constructor for Character " << name << "\n";
	for (int i = 0; i < NUM_MATERIA_SLOTS; i++)
		equipped[i] = other.equipped[i];
}

Character& Character::operator=(const Character& other)
{
	if (this != &other) {
		std::cout << "Copy assignment for Character " << name << "\n";
		name = other.name;
		for (int i = 0; i < NUM_MATERIA_SLOTS; i++)
			equipped[i] = other.equipped[i];
	}
	return *this;
}

const std::string& Character::getName() const
{
	return name;
}

void Character::equip(AMateria* materia)
{
	if (materia != nullptr) {
		for (int i = 0; i < NUM_MATERIA_SLOTS; i++) {
			if (equipped[i] == nullptr) {
				equipped[i] = materia;
				std::cout << name << " equipped " << materia->getType();
				std::cout << " to slot number " << i << "\n";
				break;
			}
		}
	}
}

void Character::unequip(int slot)
{
	if (0 <= slot && slot < NUM_MATERIA_SLOTS && equipped[slot] != nullptr) {
		std::cout << name << " unequipped " << materia->getType();
		std::cout << " from slot number " << slot << "\n";
		equipped[slot] = nullptr;
	}
}

void Character::use(int slot, ICharacter& target)
{
	if (0 <= slot && slot < NUM_MATERIA_SLOTS && equipped[slot] != nullptr) {
		equipped[slot]->use(target);
	}
}

#include <cstring>
#include <iostream>

#include "AMateria.hpp"
#include "Character.hpp"

Character::Character(const std::string& name)
	: name(name),
	  dropped(nullptr)
{
	std::cout << "Constructor for Character " << name << "\n";
	std::memset(inventory, 0, sizeof(inventory));
}

Character::~Character()
{
	std::cout << "Destructor for Character " << name << "\n";
	for (AMateria* materia: inventory)
		delete materia;
	while (dropped != nullptr) {
		Dropped* next = dropped->next;
		delete dropped->materia;
		delete dropped;
		dropped = next;
	}
}

Character::Character(const Character& other)
	: name(other.name),
	  dropped(nullptr)
{
	std::cout << "Copy constructor for Character " << name << "\n";
	std::memset(inventory, 0, sizeof(inventory));
	for (int i = 0; i < INVENTORY_SIZE; i++)
		if (other.inventory[i] != nullptr)
			inventory[i] = other.inventory[i]->clone();
}

Character& Character::operator=(const Character& other)
{
	if (this != &other) {
		std::cout << "Copy assignment for Character " << name << "\n";
		name = other.name;
		for (int i = 0; i < INVENTORY_SIZE; i++)
			delete inventory[i];
		std::memset(inventory, 0, sizeof(inventory));
		for (int i = 0; i < INVENTORY_SIZE; i++)
			if (other.inventory[i] != nullptr)
				inventory[i] = other.inventory[i]->clone();
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
		for (int i = 0; i < INVENTORY_SIZE; i++) {
			if (inventory[i] == nullptr) {
				inventory[i] = materia;
				std::cout << name << " equipped " << materia->getType();
				std::cout << " to slot number " << i << "\n";
				return;
			}
		}
		dropMateria(materia); // Couldn't find a free slot.
	}
}

void Character::unequip(int slot)
{
	if (0 <= slot && slot < INVENTORY_SIZE && inventory[slot] != nullptr) {
		std::cout << name << " unequipped " << inventory[slot]->getType();
		std::cout << " from slot number " << slot << "\n";
		dropMateria(inventory[slot]);
		inventory[slot] = nullptr;
	}
}

void Character::use(int slot, ICharacter& target)
{
	if (0 <= slot && slot < INVENTORY_SIZE && inventory[slot] != nullptr) {
		inventory[slot]->use(target);
	}
}

void Character::dropMateria(AMateria* materia)
{
	Dropped* newlyDropped = new Dropped;
	newlyDropped->next = dropped;
	newlyDropped->materia = materia;
	dropped = newlyDropped;
}

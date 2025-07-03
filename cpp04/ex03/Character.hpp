#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character: public ICharacter
{
public:
	Character(const std::string& name);
	~Character();
	Character(const Character& other);
	Character& operator=(const Character& other);
	const std::string& getName() const;
	void equip(AMateria* materia);
	void unequip(int slot);
	void use(int slot, ICharacter& target);

private:
	struct Dropped
	{
		Dropped* next;
		AMateria* materia;
	};
	void dropMateria(AMateria* materia);

	enum {INVENTORY_SIZE = 4};
	std::string name;
	AMateria* inventory[INVENTORY_SIZE];
	Dropped* dropped;
};

#endif // #ifndef CHARACTER_HPP

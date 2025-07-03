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
	enum {NUM_MATERIA_SLOTS = 4};
	std::string name;
	AMateria* equipped[NUM_MATERIA_SLOTS];
};

#endif // #ifndef CHARACTER_HPP

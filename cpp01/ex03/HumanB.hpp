#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
public:
	HumanB(const std::string& name);
	~HumanB();
	HumanB(const HumanB& other);
	HumanB& operator=(const HumanB& other);
	void setWeapon(const Weapon& newWeapon);
	void attack();

private:
	std::string name;
	const Weapon* weapon;
};

#endif // #ifndef HUMANB_HPP

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
public:
	HumanA(const std::string& name, Weapon& weapon);
	~HumanA();
	HumanA(const HumanA& other);
	HumanA& operator=(const HumanA& other);
	void attack();

private:
	std::string name;
	Weapon& weapon;
};

#endif // #ifndef HUMANA_HPP

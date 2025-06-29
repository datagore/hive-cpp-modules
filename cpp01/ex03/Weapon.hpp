#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
public:
	Weapon();
	~Weapon();
	Weapon(const Weapon& other);
	Weapon& operator=(const Weapon& other);
	Weapon(const std::string& type);

	const std::string& getType() const;
	void setType(const std::string& newType);

private:
	std::string type;
};

#endif // #ifndef WEAPON_HPP

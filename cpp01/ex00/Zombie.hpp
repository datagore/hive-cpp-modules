#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
public:
	Zombie();
	Zombie(const std::string& name);
	Zombie(const Zombie& other);
	Zombie& operator=(const Zombie& other);
	~Zombie();

	void announce(void);

private:
	std::string name;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif // #ifndef ZOMBIE_HPP

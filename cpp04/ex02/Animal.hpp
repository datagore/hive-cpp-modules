#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
public:
	Animal();
	virtual ~Animal();
	Animal(const Animal& other);
	Animal& operator=(const Animal& other);
	virtual void makeSound() = 0;
	const std::string& getType() const;

protected:
	Animal(const std::string& type);
	std::string type;
};

#endif // #ifndef ANIMAL_HPP

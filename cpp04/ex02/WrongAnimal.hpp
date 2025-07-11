#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal
{
public:
	WrongAnimal();
	virtual ~WrongAnimal();
	WrongAnimal(const WrongAnimal& other);
	WrongAnimal& operator=(const WrongAnimal& other);
	void makeSound() const;
	const std::string& getType() const;

protected:
	WrongAnimal(const std::string& type);
	std::string type;
};

#endif // #ifndef WRONGANIMAL_HPP

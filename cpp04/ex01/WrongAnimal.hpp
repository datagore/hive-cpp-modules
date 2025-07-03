#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

class WrongAnimal
{
public:
	WrongAnimal();
	~WrongAnimal();
	WrongAnimal(const WrongAnimal& other);
	WrongAnimal& operator=(const WrongAnimal& other);
	void makeSound();
};

#endif // #ifndef WRONGANIMAL_HPP

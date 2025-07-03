#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
public:
	Brain();
	~Brain();
	Brain(const Brain& other);
	Brain& operator=(const Brain& other);

	enum {NUM_THOUGHTS = 100};
	const std::string& getThought(int index) const;
	void setThought(int index, const std::string& thought);

private:
	std::string thoughts[NUM_THOUGHTS];
};

#endif // #ifndef BRAIN_HPP

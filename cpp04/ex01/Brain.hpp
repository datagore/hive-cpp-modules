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

	std::string getIdea(int index) const;
	void setIdea(int index, const std::string& idea);
	enum {NUM_IDEAS = 100};

private:
	std::string ideas[NUM_IDEAS];
};

#endif // #ifndef BRAIN_HPP

#include <iostream>
#include <utility>

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

Harl::Harl(const Harl&)
{
}

Harl& Harl::operator=(const Harl&)
{
	return *this;
}

void Harl::complain(std::string levelName)
{
	typedef void (Harl::*Function)(void);
	static const Function functions[] = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error,
	};
	int level = getLogLevel(levelName);
	if (level != -1)
		(*this.*functions[level])();
}

int Harl::getLogLevel(const std::string& level)
{
	static const std::string levelNames[] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR",
	};
	const int numLevels = sizeof(levelNames) / sizeof(*levelNames);
	for (int i = 0; i < numLevels; i++)
		if (level == levelNames[i])
			return i;
	return -1;
}

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-"
				 "pickle-special-ketchup burger. I really do!\n";
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You "
				 "didn't put enough bacon in my burger! If you did, I wouldn't "
				 "be asking for more!\n";
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I've "
				 "been coming for years whereas you started working here since "
				 "last month.\n";
}

void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

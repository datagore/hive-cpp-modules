#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl
{
public:
	Harl();
	~Harl();
	Harl(const Harl& other);
	Harl& operator=(const Harl& other);
	void complain(std::string level);

private:
	static int getLogLevel(const std::string& level);
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
};

#endif // #ifndef HARL_HPP

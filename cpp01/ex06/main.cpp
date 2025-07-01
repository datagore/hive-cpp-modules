#include <iostream>

#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl harl;
	int level = argc == 2 ? harl.getLogLevel(argv[1]) : -1;
	switch (level) {
		case 0:
			std::cout << "[ DEBUG ]\n";
			harl.complain("DEBUG");
			std::cout << std::endl;
			// Fall through
		case 1:
			std::cout << "[ INFO ]\n";
			harl.complain("INFO");
			std::cout << std::endl;
			// Fall through
		case 2:
			std::cout << "[ WARNING ]\n";
			harl.complain("WARNING");
			std::cout << std::endl;
			// Fall through
		case 3:
			std::cout << "[ ERROR ]\n";
			harl.complain("ERROR");
			std::cout << std::endl;
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
			break;
	}
}

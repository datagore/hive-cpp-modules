#include <iostream>

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	try {
	if (argc == 2)
		ScalarConverter::convert(argv[1]);
	} catch (std::exception& exception) {
		std::cout << exception.what() << std::endl;
	}
}

#include <iostream>

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	try {
		ScalarConverter::convert(argc == 2 ? argv[1] : "");
	} catch (std::exception& exception) {
		std::cout << exception.what() << std::endl;
	}
}

#include <cctype>
#include <iostream>
#include <string_view>

int main(int argc, char **argv)
{
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < argc; i++)
		for (char c: std::string_view(argv[i]))
			std::cout << static_cast<char>(std::toupper(c));
	std::cout << std::endl;
}

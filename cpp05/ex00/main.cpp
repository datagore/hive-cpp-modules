#include "Bureaucrat.hpp"

// Helper macros for applying ANSI color codes to string of text.
#define color(text, number) ("\x1b[1;" #number "m" text "\x1b[0m")
#define yellow(text) color(text, 33)
#define green(text)  color(text, 32)
#define red(text)    color(text, 31)

int main()
{
	std::cout << yellow("Test #1:") << " Construct with a too high grade\n";
	try {
		Bureaucrat bureaucrat("Zero", 0);
	} catch (std::exception& exception) {
		std::cout << red("Error ") << exception.what() << "\n";
	}

	std::cout << yellow("\nTest #2:") << " Construct with a too low grade\n";
	try {
		Bureaucrat bureaucrat("Lowbie", 151);
	} catch (std::exception& exception) {
		std::cout << red("Error ") << exception.what() << "\n";
	}

	std::cout << yellow("\nTest #3:") << " Construct with an acceptable grade\n";
	try {
		Bureaucrat bureaucrat("Normie", 150);
		std::cout << green("Constructed ") << bureaucrat;
	} catch (std::exception& exception) {
		std::cout << red("Error ") << exception.what() << "\n";
	}
}

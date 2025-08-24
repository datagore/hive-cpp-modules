#include <iostream>

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    try {
        PmergeMe pmergeMe(argc, argv);
    } catch (const std::exception& exception) {
        std::cout << ANSI_RED "Error: " ANSI_RESET << exception.what() << "\n";
    }
}

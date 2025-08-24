#include <iostream>

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    try {
        PmergeMe pmergeMe(argc, argv);
    } catch (const std::exception& exception) {
        std::cout << "Error: " << exception.what() << "\n";
    }
}

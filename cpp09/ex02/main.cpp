#include <climits>
#include <cstdlib>
#include <iostream>
#include <stdexcept>

#include "PmergeMe.hpp"

// Read a single number from the command line. Check that it's actually a valid
// positive int value.

int parseInt(const char* string)
{
    char* end = nullptr;
    long number = strtol(string, &end, 10);
    if (end != nullptr && *end != '\0')
        throw std::invalid_argument("non-numeric argument");
    if (number <= 0)
        throw std::invalid_argument("non-positive argument");
    if (number > INT_MAX)
        throw std::overflow_error("argument too large");
    return number;
}

// Read numbers from the command line into a vector, then pass those numbers to
// the main merge-insertion sort program.

int main(int argc, char **argv)
{
    try {
        if (argc <= 1)
            throw std::invalid_argument("not enough arguments");
        std::vector<int> numbers(argc - 1);
        for (int i = 0; i < argc - 1; i++)
            numbers[i] = parseInt(argv[i + 1]);
        PmergeMe pmergeMe(numbers);
    } catch (const std::exception& exception) {
        std::cerr << ANSI_RED "Error: " ANSI_RESET << exception.what() << "\n";
    }
}

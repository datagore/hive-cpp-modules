#include <chrono>
#include <climits>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <list>
#include <stdexcept>
#include <vector>

#include "PmergeMe.hpp"

// ANSI escape codes.
#define ANSI_RED    "\x1b[1;31m"
#define ANSI_GREEN  "\x1b[1;32m"
#define ANSI_YELLOW "\x1b[1;33m"
#define ANSI_RESET  "\x1b[0m"

// Type aliases for overly long <chrono> types.
using TimePoint = std::chrono::time_point<std::chrono::steady_clock>;
using TimeDelta = std::chrono::duration<double, std::micro>;

// Print all numbers in a container.
template <class Container>
void printNumbers(const char* label, Container container)
{
    std::cout << ANSI_YELLOW << label << ANSI_RESET;
    for (int number: container)
        std::cout << number << " ";
    std::cout << std::endl;
}

// Print the timing for one container.
void printTiming(size_t numbers, TimeDelta timing, const char* container)
{
    std::cout << "Time to sort " ANSI_RED << numbers;
    std::cout << ANSI_RESET " numbers with a " ANSI_GREEN << container;
    std::cout << ANSI_RESET ": " ANSI_YELLOW << timing << ANSI_RESET "\n";
}

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

// Sort numbers using a std::vector. Returns the amount of time taken.
TimeDelta vectorSort(std::vector<int>& numbers)
{
    TimePoint start_time = std::chrono::steady_clock::now();
    (void) numbers;
    TimePoint end_time = std::chrono::steady_clock::now();
    return end_time - start_time;
}

// Sort numbers using a std::list. Returns the amount of time taken.
TimeDelta listSort(const std::vector<int>& source)
{
    TimePoint start_time = std::chrono::steady_clock::now();
    auto numbers = std::list<int>(source.begin(), source.end());
    (void) numbers;
    TimePoint end_time = std::chrono::steady_clock::now();
    return end_time - start_time;
}

PmergeMe::PmergeMe(int argc, char** argv)
{
    // Read numbers from the command line.
    if (argc <= 1)
        throw std::invalid_argument("not enough arguments");
    std::vector<int> numbers(argc - 1);
    for (int i = 0; i < argc - 1; i++)
        numbers[i] = parseInt(argv[i + 1]);

    // Sort using two different containers.
    printNumbers("Before: ", numbers);
    TimeDelta list_time = listSort(numbers);
    TimeDelta vector_time = vectorSort(numbers);
    printNumbers("After:  ", numbers);

    // Print timings.
    printTiming(numbers.size(), vector_time, "std::vector");
    printTiming(numbers.size(), list_time,   "std::list");
}

#include <algorithm>
#include <chrono>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <list>
#include <stdexcept>
#include <vector>

#include "PmergeMe.hpp"

////////////////////////////////////////////////////////////////////////////////
//
// Sorting using std::vector
//
////////////////////////////////////////////////////////////////////////////////

void sortVector(std::vector<int>& numbers)
{
    (void) numbers;
}

// Sort numbers using a std::vector. Returns the time taken in microseconds.
double timeSortVector(std::vector<int>& numbers)
{
    auto t0 = std::chrono::steady_clock::now();
    sortVector(numbers);
    auto t1 = std::chrono::steady_clock::now();
    return std::chrono::duration<double, std::micro>(t1 - t0).count();
}

////////////////////////////////////////////////////////////////////////////////
//
// Sorting using std::list
//
////////////////////////////////////////////////////////////////////////////////

void sortList(std::list<int>& numbers)
{
    (void) numbers;
}

// Sort numbers using a std::list. Returns the time taken in microseconds.
double timeSortList(const std::vector<int>& source)
{
    auto t0 = std::chrono::steady_clock::now();
    auto numbers = std::list<int>(source.begin(), source.end());
    sortList(numbers);
    auto t1 = std::chrono::steady_clock::now();
    return std::chrono::duration<double, std::micro>(t1 - t0).count();
}

////////////////////////////////////////////////////////////////////////////////
//
// Entry point
//
////////////////////////////////////////////////////////////////////////////////

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
void printTiming(size_t numbers, double microsecs, const char* container)
{
    std::cout << "Time to sort " ANSI_RED << numbers << ANSI_RESET;
    std::cout << " numbers with a " ANSI_GREEN << container << ": ";
    std::cout << ANSI_YELLOW << microsecs << " µs" ANSI_RESET "\n";
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

// Read command line arguments and sort using the different containers, and
// print the timings for each.
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
    double list_time = timeSortList(numbers);
    double vector_time = timeSortVector(numbers);
    printNumbers("After:  ", numbers);

    // Double check that the numbers are actually sorted.
    if (!std::is_sorted(numbers.begin(), numbers.end()))
        throw std::runtime_error("numbers are not sorted");

    // Print timings.
    printTiming(numbers.size(), vector_time, "std::vector");
    printTiming(numbers.size(), list_time,   "std::list");
}

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

// Sort the elements of array `a` between indices `beg` and `end`, using the
// same range of elements in array `b` for temporary storage.

void sortVec(std::vector<int>& a, std::vector<int>& b, size_t beg, size_t end)
{
    if (end - beg > 1) { // Base case: An array of length one is already sorted.
        size_t mid = (beg + end) / 2; // Split the range in two halves.
        sortVec(b, a, beg, mid); // Sort the lower half.
        sortVec(b, a, mid, end); // Sort the upper half.
        for (size_t p = beg, q = beg, r = mid; p < end; p++)
            a[p] = b[q < mid && (r >= end || b[q] <= b[r]) ? q++ : r++];
    }
}

// Sort numbers using a std::vector. Returns the time taken in microseconds.

double timeSortVec(std::vector<int>& numbers)
{
    std::vector<int> temp = numbers;
    auto t0 = std::chrono::steady_clock::now();
    sortVec(numbers, temp, 0, numbers.size());
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
    auto numbers = std::list<int>(source.begin(), source.end());
    auto t0 = std::chrono::steady_clock::now();
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

    // Make a sorted copy of the numbers for later reference.
    std::vector<int> sorted = numbers;
    std::sort(sorted.begin(), sorted.end());

    // Sort using two different containers.
    printNumbers("Before: ", numbers);
    double listTime = timeSortList(numbers);
    double vectorTime = timeSortVec(numbers);
    printNumbers("After:  ", numbers);

    // Print timings.
    printTiming(numbers.size(), listTime,   "std::list");
    printTiming(numbers.size(), vectorTime, "std::vector");

    // Double-check that the numbers were actually sorted.
    if (!std::equal(numbers.begin(), numbers.end(), sorted.begin()))
        throw std::runtime_error("numbers are not sorted");
}

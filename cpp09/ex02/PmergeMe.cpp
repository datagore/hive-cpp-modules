#include <algorithm>
#include <chrono>
#include <deque>
#include <iostream>
#include <stdexcept>

#include "PmergeMe.hpp"

////////////////////////////////////////////////////////////////////////////////
//
// Ford-Johnson algorithm
//
////////////////////////////////////////////////////////////////////////////////

// Get the difference between successive Jacobstahl numbers. Jacobstahl numbers
// can be calculated using the formula J(n) = ((1 << n) + (n % 2 * 2 - 1)) / 3.
// The function below is derived by rearranging and simplifying J(n+2) - J(n+1).
// Starting from n = 0, this generates the sequence 2, 2, 6, 10, 22, 42, 86...

size_t jacobstahl(size_t n)
{
    return (4 << n) / 3 + ((n + 1) % 2);
}

// Move groups of `count` integers from the index `src` to the index `dst`,
// shifting other elements to make room.

template <class Container>
void shift(Container& a, size_t dst, size_t src, size_t count)
{
    auto first = a.begin() + std::min(src, dst);
    auto middle = a.begin() + src + (src < dst) * count;
    auto last = a.begin() + std::max(src, dst) + count;
    std::rotate(first, middle, last);
}

// Use binary search to insert a group of `count` integers at index `src` into
// the first `max` elements of the sequence.

template <class Container>
void insert(Container& n, size_t max, size_t src, size_t count)
{
    size_t min = 0;
    while (min < max) {
        size_t mid = (min + max) / 2;
        if (n[mid * count + count - 1] < n[src * count + count - 1])
            min = mid + 1;
        else
            max = mid;
    }
    shift(n, min * count, src * count, count);
}

// Merge groups of `count` integers, first by moving odd-numbered ones to the
// front of the sequence (including also the first group in the sequence), and
// then repeatedly inserting the even-numbered ones into their right place using
// binary search.

template <class Container>
void merge(Container& n, size_t count)
{
    // Move the larger, even-numbered elements to the front of the array.
    size_t elems = n.size() / count;
    size_t end = n.size() / (count * 2) + 1;
    for (size_t i = 2; i < end; i++)
        shift(n, i * count, i * count * 2 - count, count);

    // Insert the remaining elements in an order determined by the Jacobstahl
    // numbers.
    size_t group = 0;
    size_t offset = 0;
    for (size_t i = end; i < elems; i++) {
        if (offset == 0)
            offset = std::min(elems - i, jacobstahl(group++));
        insert(n, std::min(i, (2ul << group) - 1), --offset + i, count);
    }
}

// Divide a sequence into groups of `count` numbers. Swap adjacent pairs of
// groups so that the last number in the first group is always lower than the
// last number in the second group.

template <class Container>
void divide(Container& n, size_t count)
{
    for (size_t i = 0; i < n.size() / count - 1; i += 2)
        if (n[i * count + count - 1] > n[(i + 1) * count + count - 1])
            shift(n, i * count, (i + 1) * count, count);
}

// Sort a sequence by recursively dividing and merging groups of numbers.

template <class Container>
void sort(Container& n, size_t count = 1)
{
    divide(n, count);
    if (n.size() / (count * 2) > 0)
        sort(n, count * 2);
    merge(n, count);
}

////////////////////////////////////////////////////////////////////////////////
//
// Comparison program
//
////////////////////////////////////////////////////////////////////////////////

// Sort a container, and also measure how long the sorting procedure takes.

template <class Container>
double timeSortContainer(Container& container)
{
    auto start = std::chrono::steady_clock::now();
    sort(container);
    auto end = std::chrono::steady_clock::now();
    return std::chrono::duration<double, std::micro>(end - start).count();
}

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
    std::cout << "Time to sort " ANSI_GREEN << numbers << ANSI_RESET;
    std::cout << " numbers with a " ANSI_GREEN << container << ": ";
    std::cout << ANSI_YELLOW << microsecs << " µs" ANSI_RESET "\n";
}

PmergeMe::PmergeMe(const std::vector<int>& numbers)
{
    // Copy the input into two containers.
    std::vector<int> vec(numbers.begin(), numbers.end());
    std::deque<int>  deq(numbers.begin(), numbers.end());

    // Sort the two containers, timing how long each one takes.
    double vecTime = timeSortContainer(vec);
    double deqTime = timeSortContainer(deq);

    // Print the unsorted and sorted numbers.
    printNumbers("Before: ", numbers);
    printNumbers("After:  ", vec);

    // Print timings.
    printTiming(numbers.size(), vecTime, "std::vector");
    printTiming(numbers.size(), deqTime, "std::deque");

    // Double-check that the numbers were actually sorted.
    if (!std::is_sorted(vec.begin(), vec.end())
     || !std::is_sorted(deq.begin(), deq.end()))
        throw std::runtime_error("numbers are not sorted");
}

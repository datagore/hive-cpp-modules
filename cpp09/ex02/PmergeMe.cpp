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

// Move a group of `n` integers from the index `src` to the index `dst`,
// shifting other elements to make room.

template <class Container>
void move(Container& c, size_t dst, size_t src, size_t n)
{
    auto first = c.begin() + std::min(src, dst);
    auto middle = c.begin() + src + (src < dst) * n;
    auto last = c.begin() + std::max(src, dst) + n;
    std::rotate(first, middle, last);
}

// Use binary search to insert a group of `n` integers at index `src` into the
// first `max` elements of the sequence.

template <class Container>
void insert(Container& c, size_t max, size_t src, size_t n)
{
    size_t min = 0;
    while (min < max) {
        size_t mid = (min + max) / 2;
        if (c[mid * n + n - 1] < c[src * n + n - 1])
            min = mid + 1;
        else
            max = mid;
    }
    move(c, min * n, src * n, n);
}

// Merge groups of `n` integers, first by moving odd-numbered ones to the front
// of the sequence (including also the first group in the sequence), and then
// repeatedly inserting the even-numbered ones into their right place using
// binary search.

template <class Container>
void merge(Container& c, size_t n)
{
    // Move the larger, even-numbered elements to the front of the array.
    size_t elems = c.size() / n;
    size_t end = c.size() / (n * 2) + 1;
    for (size_t i = 2; i < end; i++)
        move(c, i * n, i * n * 2 - n, n);

    // Insert the remaining elements in an order determined by the Jacobstahl
    // numbers.
    size_t group = 0;
    size_t offset = 0;
    for (size_t i = end; i < elems; i++) {
        if (offset == 0)
            offset = std::min(elems - i, jacobstahl(group++));
        insert(c, std::min<size_t>(i, (2 << group) - 1), --offset + i, n);
    }
}

// Divide a sequence into groups of `n` numbers. Swap adjacent pairs of groups
// so that the last number in the first group is always lower than the last
// number in the second group.

template <class Container>
void divide(Container& c, size_t n)
{
    for (size_t i = 0; i < c.size() / n - 1; i += 2)
        if (c[i * n + n - 1] > c[(i + 1) * n + n - 1])
            move(c, i * n, (i + 1) * n, n);
}

// Sort a sequence by recursively dividing and merging groups of numbers.

template <class Container>
void sort(Container& c, size_t n = 1)
{
    divide(c, n);
    if (c.size() / (n * 2) > 0)
        sort(c, n * 2);
    merge(c, n);
}

////////////////////////////////////////////////////////////////////////////////
//
// Comparison program
//
////////////////////////////////////////////////////////////////////////////////

// Copy numbers from the iterators `begin` and `end` into a container, then sort
// the container. Measure how long the whole process took; return the time
// taken in microseconds (us).

template <class Container, class Iterator>
double timeSortContainer(Container& container, Iterator begin, Iterator end)
{
    auto start = std::chrono::steady_clock::now();
    container.assign(begin, end);
    sort(container);
    auto stop = std::chrono::steady_clock::now();
    return std::chrono::duration<double, std::micro>(stop - start).count();
}

// Print all numbers in a container.

template <class Container>
void printNumbers(const char* label, const Container& container)
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
    std::cout << ANSI_YELLOW << microsecs << " us" ANSI_RESET "\n";
}

// Test program entry point. Takes a sequence of numbers and sorts them using
// two different containers, printing out the timings for each one.

PmergeMe::PmergeMe(const std::vector<int>& unsorted)
{
    // Create two different containers to be sorted.
    std::vector<int> vec;
    std::deque<int> deq;

    // Copy the input into each container, then sort them.
    double vecTime = timeSortContainer(vec, unsorted.begin(), unsorted.end());
    double deqTime = timeSortContainer(deq, unsorted.begin(), unsorted.end());

    // Print the unsorted and sorted numbers.
    printNumbers("Before: ", unsorted);
    printNumbers("After:  ", vec);

    // Print timings.
    printTiming(vec.size(), vecTime, "std::vector");
    printTiming(deq.size(), deqTime, "std::deque");

    // Verify that the numbers were actually sorted.
    if (!std::is_sorted(vec.begin(), vec.end())
     || !std::is_sorted(deq.begin(), deq.end()))
        throw std::runtime_error("numbers are not sorted");
}

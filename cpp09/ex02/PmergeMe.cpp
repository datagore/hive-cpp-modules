#include <algorithm>
#include <chrono>
#include <climits>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <stdexcept>
#include <vector>

#include "PmergeMe.hpp"

struct Counter
{
    Counter() = default;
    Counter(int value): value(value) {}
    auto operator<=>(const Counter& other) const { comparisons++; return value <=> other.value; }
    operator int() const { return value; }
    static size_t comparisons;
    int value = 0;
};
size_t Counter::comparisons;

template <class Container>
void print(const Container& container)
{
    int index = 0;
    for (auto number: container) {
        (void) number;
        printf("%2d ", index++);
    }
    printf(" (INDICES)\n");
    for (auto number: container)
        printf("%2d ", int(number));
}

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
    printf("Inserting %zu-sized group from %zu to %zu\n", count, src * count, max * count);
    print(n);
    printf("\n");
    size_t start = Counter::comparisons;
    size_t min = 0;
    while (min < max) {
        size_t mid = (min + max) / 2;
        if (n[mid * count + count - 1] < n[src * count + count - 1])
            min = mid + 1;
        else
            max = mid;
    }
    shift(n, min * count, src * count, count);
    print(n);
    printf(" (%zu comparisons)\n", Counter::comparisons - start);
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
        insert(n, i, --offset + i, count);
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

double timeSortVec(std::vector<int>& numbers)
{
    auto t0 = std::chrono::steady_clock::now();
    sort(numbers);
    auto t1 = std::chrono::steady_clock::now();
    return std::chrono::duration<double, std::micro>(t1 - t0).count();
}

double timeSortDeque(const std::vector<int>& source)
{
    auto numbers = std::deque<int>(source.begin(), source.end());
    auto t0 = std::chrono::steady_clock::now();
    sort(numbers);
    auto t1 = std::chrono::steady_clock::now();
    return std::chrono::duration<double, std::micro>(t1 - t0).count();
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

#if 0
    // Make a sorted copy of the numbers for later reference.
    std::vector<int> sorted = numbers;
    std::sort(sorted.begin(), sorted.end());

    // Sort using two different containers.
    printNumbers("Before: ", numbers);
    double dequeTime = timeSortDeque(numbers);
    double vectorTime = timeSortVec(numbers);
    printNumbers("After:  ", numbers);

    // Print timings.
    printTiming(numbers.size(), dequeTime,  "std::deque");
    printTiming(numbers.size(), vectorTime, "std::vector");

    // Double-check that the numbers were actually sorted.
    if (!std::equal(numbers.begin(), numbers.end(), sorted.begin()))
        throw std::runtime_error("numbers are not sorted");
#endif

    // numbers = std::vector<int> {3, 0, 2, 5, 6, 1, 9, 10};
    std::vector<Counter> counters(numbers.size());
    for (size_t i = 0; i < counters.size(); i++)
        counters[i] = numbers[i];
    sort(counters);
    printf("Comparisons: %zu\n", Counter::comparisons);
    for (size_t i = 0; i < counters.size(); i++)
        counters[i] = numbers[i];
    Counter::comparisons = 0;
    std::sort(counters.begin(), counters.end());
    printf("Comparisons: %zu\n", Counter::comparisons);
}

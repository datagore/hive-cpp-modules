#include <algorithm>
#include <iostream>
#include <vector>

#include "PmergeMe.hpp"

#if 1

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
            max = mid - 0;
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

template <class Container>
void print(const char* label, const Container& numbers)
{
    std::cout << label;
    for (int number: numbers)
        std::cout << number << " ";
    std::cout << "\n";
}

int main(int argc, const char **argv)
{
    std::vector<int> numbers(argc - 1);
    for (int i = 1; i < argc; i++)
        numbers[i - 1] = std::atoi(argv[i]);
    print("Before: ", numbers);
    sort(numbers);
    print("After:  ", numbers);
    bool sorted = std::is_sorted(numbers.begin(), numbers.end());
    printf("Sorted: %s\n" ANSI_RESET, sorted ? ANSI_GREEN "YES" : ANSI_RED "NO");
}

#else
int main(int argc, char **argv)
{
    try {
        PmergeMe pmergeMe(argc, argv);
    } catch (const std::exception& exception) {
        std::cout << ANSI_RED "Error: " ANSI_RESET << exception.what() << "\n";
    }
}
#endif

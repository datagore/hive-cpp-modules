#include <algorithm>
#include <iostream>
#include <vector>

#include "PmergeMe.hpp"

#if 1

// Move groups of `size` integers from the index `src` to the index `dst`,
// shifting other elements to make room.

template <class Container>
void shift(Container& a, size_t dst, size_t src, size_t size)
{
    auto first = a.begin() + std::min(src, dst);
    auto middle = a.begin() + src + (src < dst) * size;
    auto last = a.begin() + std::max(src, dst) + size;
    std::rotate(first, middle, last);
}

// Use binary search to insert the group of `size` integers at index `src` into
// the start of the sequence, up to the index `max`.

template <class Container>
void insert(Container& n, size_t max, size_t src, size_t size)
{
    size_t min = 0;
    while (min < max) {
        size_t mid = (min + max) / 2;
        if (n[mid * size + size - 1] < n[src * size + size - 1])
            min = mid + 1;
        else
            max = mid - 0;
    }
    shift(n, min * size, src * size, size);
}

// Merge groups of `size` integers, first by moving odd-numbered ones to the
// front of the sequence (including also the first group in the sequence), and
// then repeatedly inserting the even-numbered ones into their right place using
// binary search.

template <class Container>
void merge(Container& n, size_t size)
{
    size_t elems = n.size() / size;
    size_t end = n.size() / (size * 2) + 1;
    for (size_t i = 2; i < end; i++)
        shift(n, i * size, i * size * 2 - size, size);
    for (size_t src = end; src < elems; src++)
        insert(n, end + size, src, size);
}

// Divide a sequence into groups of `size` numbers. Swap adjacent pairs of
// groups so that the last number in the first group is always lower than the
// last number in the second group.

template <class Container>
void divide(Container& n, size_t size)
{
    for (size_t i = 0; i < n.size() / size - 1; i += 2)
        if (n[i * size + size - 1] > n[(i + 1) * size + size - 1])
            shift(n, i * size, (i + 1) * size, size);
}

// Sort a sequence by recursively dividing and merging groups of numbers.

template <class Container>
void sort(Container& n, size_t size = 1)
{
    divide(n, size);
    if (size * 4 < n.size())
        sort(n, size * 2);
    merge(n, size);
}

template <class Container>
void print(const char* label, const Container& numbers)
{
    std::cout << label;
    for (int number: numbers)
        std::cout << number << " ";
    std::cout << "\n";
}

int main()
{
    std::vector numbers = {11, 2, 17, 0, 16, 8, 6, 15, 10, 3, 21, 1, 18, 9, 14, 19, 12, 5, 4, 20, 13, 7};
    print("Before: ", numbers);
    sort(numbers);
    print("After:  ", numbers);
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

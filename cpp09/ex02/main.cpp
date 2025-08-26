#include <algorithm>
#include <iostream>
#include <vector>

#include "PmergeMe.hpp"

#if 1

template <typename T>
void print(const T& numbers)
{
    for (int number: numbers)
        std::cout << number << " ";
    std::cout << "\n";
}

template <typename T>
void moveElement(T& a, size_t i, size_t j, size_t s)
{
    auto first = a.begin() + std::min(i, j);
    auto middle = a.begin() + j + (j < i) * s;
    auto last = a.begin() + std::max(i, j) + s;
    std::rotate(first, middle, last);
}

template <typename T>
void merge(T& n, size_t s)
{
    for (size_t i = s * 2; i < n.size(); i += s * 2) {
    }
}

template <typename T>
void divide(T& n, size_t s)
{
    for (size_t i = 0; i + s * 2 - 1 < n.size(); i += s * 2) {
        if  (n[i + s - 1] > n[i + s * 2 - 1]) {
            std::swap_ranges(n.begin() + i, n.begin() + i + s, n.begin() + i + s);
        }
    }
    if (s * 4 < n.size())
        divide(n, s * 2);
    if (s >= 4)
        merge(n, s);
}

template <typename T>
void sort(T& numbers)
{
    divide(numbers, 1);
}

int main()
{
    std::vector numbers = {11, 2, 17, 0, 16, 8, 6, 15, 10, 3, 21, 1, 18, 9, 14, 19, 12, 5, 4, 20, 13, 7};
    sort(numbers);
    print(numbers);
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

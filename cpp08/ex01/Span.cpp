#include <algorithm>
#include <climits>
#include <stdexcept>

#include "Span.hpp"

Span::Span(unsigned int n)
    : numbers(n)
{
}

void Span::addNumber(int number)
{
    if (storedNumbers >= numbers.size())
        throw std::out_of_range("span is full");
    numbers[storedNumbers++] = number;
}

unsigned int Span::shortestSpan() const
{
    if (storedNumbers < 2)
        throw std::logic_error("span is too short");
    std::sort(numbers.begin(), numbers.begin() + storedNumbers);
    unsigned int shortest = UINT_MAX;
    for (size_t i = 1; i < storedNumbers; i++) {
        long higher = static_cast<long>(numbers[i - 0]);
        long lower  = static_cast<long>(numbers[i - 1]);
        shortest = std::min<unsigned>(shortest, higher - lower);
    }
    return shortest;
}

unsigned int Span::longestSpan() const
{
    if (storedNumbers < 2)
        throw std::logic_error("span is too short");
    long max = *std::max_element(numbers.begin(), numbers.end());
    long min = *std::min_element(numbers.begin(), numbers.end());
    return max - min;
}

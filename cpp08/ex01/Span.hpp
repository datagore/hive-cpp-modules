#pragma once

#include <vector>

class Span
{
public:
    Span() = default;
    ~Span() = default;
    Span(const Span&) = default;
    Span& operator=(const Span&) = default;

    explicit Span(unsigned int n);
    void addNumber(int number);
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

    template <typename InputIt>
    void addNumbers(InputIt first, InputIt last)
    {
        while (first != last)
            addNumber(*first++);
    }

private:
    mutable std::vector<int> numbers;
    unsigned int storedNumbers = 0;
};

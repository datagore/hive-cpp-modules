#include <climits>
#include <cstdlib>
#include <iostream>

#include "Span.hpp"

// ANSI escape codes.
#define ANSI_GREEN   "\x1b[1;32m"
#define ANSI_RED     "\x1b[1;31m"
#define ANSI_YELLOW  "\x1b[1;33m"
#define ANSI_RESET   "\x1b[0m"
#define ANSI_CLEAR   "\x1b[2J"

// Helper macros for applying color to string literals.
#define RED(text)   ANSI_RED   text ANSI_RESET
#define GREEN(text) ANSI_GREEN text ANSI_RESET

void test_case(const char *label, void (*test_code)())
{
    static int counter;
    std::cout << ANSI_YELLOW "Test #" << ++counter << ": ";
    std::cout << ANSI_RESET << label << "\n";
    try {
        test_code();
    } catch (const std::exception& exception) {
        std::cout << RED("ERROR: ") << exception.what() << "\n";
    }
    std::cout << "\n";
}

int main()
{
    std::cout << ANSI_CLEAR;

    test_case("Numbers from the subject (using iterators)", [] {
        const int numbers[] = {6, 3, 17, 9, 11};
        Span span(5);
        span.addNumbers(std::begin(numbers), std::end(numbers));
        std::cout << GREEN("Shortest span: ") << span.shortestSpan() << "\n";
        std::cout << GREEN("Longest span: ") << span.longestSpan() << "\n";
    });

    test_case("INT_MIN and INT_MAX", [] {
        Span span(2);
        span.addNumber(INT_MIN);
        span.addNumber(INT_MAX);
        std::cout << GREEN("Shortest span: ") << span.shortestSpan() << "\n";
        std::cout << GREEN("Longest span: ") << span.longestSpan() << "\n";
    });

    test_case("10,000 random numbers", [] {
        Span span(10000);
        srand((long) &span);
        for (int i = 0; i < 10000; i++)
            span.addNumber(rand());
        std::cout << GREEN("Shortest span: ") << span.shortestSpan() << "\n";
        std::cout << GREEN("Longest span: ") << span.longestSpan() << "\n";
    });

    test_case("100,000 random numbers", [] {
        Span span(100000);
        srand((long) &span);
        for (int i = 0; i < 100000; i++)
            span.addNumber(rand());
        std::cout << GREEN("Shortest span: ") << span.shortestSpan() << "\n";
        std::cout << GREEN("Longest span: ") << span.longestSpan() << "\n";
    });

    test_case("1,000,000 random numbers", [] {
        Span span(1000000);
        srand((long) &span);
        for (int i = 0; i < 1000000; i++)
            span.addNumber(rand());
        std::cout << GREEN("Shortest span: ") << span.shortestSpan() << "\n";
        std::cout << GREEN("Longest span: ") << span.longestSpan() << "\n";
    });

    test_case("Adding too many numbers to a span", [] {
        Span span(5);
        for (int i = 0; i < 10; i++) {
            span.addNumber(i);
            std::cout << GREEN("Added number: ") << i << "\n";
        }
    });

    test_case("Adding a number to an empty span", [] {
        Span span(0);
        span.addNumber(42);
    });

    test_case("shortestSpan with just one number", [] {
        Span span(3);
        span.addNumber(1);
        span.shortestSpan();
    });

    test_case("longestSpan with just one number", [] {
        Span span(3);
        span.addNumber(1);
        span.longestSpan();
    });
}

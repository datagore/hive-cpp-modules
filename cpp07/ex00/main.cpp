#include <iostream>
#include <string>

#include "whatever.hpp"

// Helper macros for applying ANSI color codes.
#define ANSI_GREEN "\x1b[1;32m"
#define ANSI_RED   "\x1b[1;31m"
#define ANSI_BLUE  "\x1b[1;36m"
#define ANSI_RESET "\x1b[0m"

#define RED(text) ANSI_RED text ANSI_RESET
#define GREEN(text) ANSI_GREEN text ANSI_RESET
#define BLUE(text) ANSI_BLUE text ANSI_RESET

// Test all three functions with mutable arguments.
template <typename T>
void test_mutable(T a, T b)
{
    std::cout
        << RED("    min") "(" << a << ", " << b << ") = " << min(a, b) << "\n"
        << GREEN("    max") "(" << a << ", " << b << ") = " << max(a, b) << "\n"
        << BLUE("    swap") "(" << a << ", " << b << ") = ";
    swap(a, b);
    std::cout << a << ", " << b << "\n\n";
}

// Test min and max with constant arguments. swap() can't be tested because it
// always modifies its arguments, so it makes no sense here.
template <typename T>
void test_const(const T a, const T b)
{
    std::cout
        << RED("    min") "(" << a << ", " << b << ") = " << min(a, b) << "\n"
        << GREEN("    max") "(" << a << ", " << b << ") = " << max(a, b) << "\n\n";
}

int main()
{
    std::cout << "Test with mutable arguments:\n\n";
    test_mutable(-1, 5);
    test_mutable(3.5f, 7.5f);
    test_mutable("abc", "def");

    std::cout << "Test with constant arguments:\n\n";
    test_const(-1, 5);
    test_const(3.5f, 7.5f);
    test_const("abc", "def");
}

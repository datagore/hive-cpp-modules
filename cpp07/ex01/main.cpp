#include <iostream>

#include "iter.hpp"

// Helper macros for applying ANSI color codes.
#define ANSI_GREEN  "\x1b[1;32m"
#define ANSI_RESET "\x1b[0m"
#define GREEN(text) ANSI_GREEN text ANSI_RESET

// Helper template for getting the length of an array.
template <typename T, size_t N>
size_t length(const T (&)[N])
{
    return N;
}

// Helper template for printing out a single value of any type.
template <typename T>
void print(const T& value)
{
    std::cout << value << " ";
}

// Helper for running a single test.
void run_test(const char *label, void (*code)())
{
    static int counter;
    std::cout << ANSI_GREEN "\nTest #" << ++counter;
    std::cout << ANSI_RESET ": " << label << "\n";
    code();
    std::cout << "\n";
}

int main()
{
    run_test("Test with a mutable array of integers", [] {
        int array[] = {0, 1, 2, 3, 4};
        iter(array, length(array), print<int>);
    });

    run_test("Test with a constant array of integers", [] {
        const int array[] = {0, 1, 2, 3, 4};
        iter(array, length(array), print<int>);
    });

    run_test("Test with a mutable array of strings", [] {
        const char* array[] = {"zero", "one", "two", "three", "four"};
        iter(array, length(array), print<const char*>);
    });

    run_test("Test with a constant array of strings", [] {
        const char* const array[] = {"zero", "one", "two", "three", "four"};
        iter(array, length(array), print<const char*>);
    });
}

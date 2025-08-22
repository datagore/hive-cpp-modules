#include <deque>
#include <iostream>
#include <list>
#include <vector>

#include "easyfind.hpp"

// Helper macros for applying ANSI color codes.
#define ANSI_RED "\x1b[1;31m"
#define ANSI_GREEN "\x1b[1;32m"
#define ANSI_YELLOW "\x1b[1;33m"
#define ANSI_RESET "\x1b[0m"

template <typename T>
void run_test(const char* label, const T& container, int value)
{
    // Print a little heading for the test case.
    static int counter;
    std::cout << "\n" ANSI_YELLOW "Test #" << ++counter << ": ";
    std::cout << ANSI_RESET << label << "\n";

    // Print out the contents of the container.
    std::cout << ANSI_GREEN "Contents: " ANSI_RESET;
    for (int value: container)
        std::cout << value << " ";
    std::cout << "\n";

    // Use easyfind to find the value and print it out if found.
    auto iterator = easyfind(container, value);
    if (iterator != std::end(container))
        std::cout << ANSI_GREEN "Found: " ANSI_RESET << *iterator << "\n";
    else
        std::cout << ANSI_RED "Not found: " ANSI_RESET << value << "\n";
}

int main()
{
    run_test("Existing value in vector", std::vector<int> {1, 2, 3, 4, 5}, 2);
    run_test("Missing value in vector", std::vector<int> {1, 2, 3, 4, 5}, 0);
    run_test("Existing value in list", std::list<int> {420, 69, 666}, 69);
    run_test("Missing value in list", std::list<int> {420, 69, 666}, -123);
    run_test("Existing value in deque", std::deque<int> {111, 222, 333}, 333);
    run_test("Missing value in deque", std::deque<int> {111, 222, 333}, -333);
    run_test("Empty container", std::vector<int> {}, 123);
}

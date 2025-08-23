#include <iostream>
#include <list>
#include <vector>

#include "MutantStack.hpp"

// ANSI escape codes.
#define ANSI_GREEN   "\x1b[1;32m"
#define ANSI_YELLOW  "\x1b[1;33m"
#define ANSI_RESET   "\x1b[0m"
#define ANSI_CLEAR   "\x1b[2J"

template <typename T>
void printContainer(const char *name, T& cont)
{
    // Print which container is being shown.
    std::cout << "Iterating over " ANSI_YELLOW << name << ANSI_RESET "\n";
    std::cout << ANSI_GREEN "    Elements: " ANSI_RESET;

    // Use the container's iterators to print out the elements.
    auto begin = cont.begin();
    auto end   = cont.end();
    while (begin != end)
        std::cout << *begin++ << " ";
    std::cout << "\n\n";
}

int main()
{
    // Clear the terminal.
    std::cout << ANSI_CLEAR;

    // Create three different containers.
    MutantStack<int> stack;
    std::list<int> list;
    std::vector<int> vector;

    // Insert the same values into all three.
    for (int i = 0; i < 10; i++) {
        stack.push(i);
        list.push_back(i);
        vector.push_back(i);
    }

    // Use the containers' iterators to show their contents.
    printContainer("MutantStack<int>", stack);
    printContainer("std::list<int>", list);
    printContainer("std::vector<int>", vector);
}

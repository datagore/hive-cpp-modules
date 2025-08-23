#include <exception>
#include <iostream>

#include "RPN.hpp"

int main(int argc, const char **argv)
{
    try {
        if (argc == 2)
            std::cout << RPN::calculate(argv[1]) << std::endl;
    } catch (const std::exception&) {
        std::cerr << "Error" << std::endl;
    }
}

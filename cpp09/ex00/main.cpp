#include <iostream>

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    try {
        if (argc != 2)
            throw std::runtime_error("could not open file.");
        queryDatabase(argv[1]);
    } catch (const std::exception& exception) {
        std::cout << "Error: " << exception.what() << "\n";
    }
}

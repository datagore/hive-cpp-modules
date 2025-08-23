#include <iostream>

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    // Build and query the exchange database.
    try {
        if (argc != 2)
            throw std::runtime_error("could not open file.");
        BitcoinExchange exchange("data.csv");
        exchange.queryDatabase(argv[1]);

    // Display any errors that occur.
    } catch (const std::exception& exception) {
        std::cout << "Error: " << exception.what() << "\n";
    }
}

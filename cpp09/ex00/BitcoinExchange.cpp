#include <algorithm>
#include <cctype>
#include <climits>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <utility>

#include "BitcoinExchange.hpp"

using StringPair = std::pair<std::string, std::string>;
using ValuePair = std::pair<std::string, double>;

// Strip spaces at the start and end of a string.
std::string stripWhitespace(std::string s)
{
    s.erase(std::remove_if(s.begin(), s.end(), ::isspace), s.end());
    return s;
}

// Read a pair of strings separated by a delimiter.
StringPair getStringPair(std::ifstream& file, char delimiter)
{
    // Read a line of text from the file.
    std::string line;
    std::getline(file, line);

    // Parse the string before the delimiter.
    size_t delimiterIndex = line.find(delimiter);
    if (delimiterIndex == line.npos)
        throw std::runtime_error("bad input => " + line);
    std::string key = stripWhitespace(line.substr(0, delimiterIndex));

    // Parse the string after the delimiter.
    std::string value = stripWhitespace(line.substr(delimiterIndex + 1));
    if (value.find(delimiter) != value.npos)
        throw std::runtime_error("unexpected delimiter");
    return {key, value};
}

ValuePair getValuePair(std::ifstream& file, char delimiter)
{
    // Read a pair of strings; convert the second string to a number.
    size_t end = -1;
    StringPair pair = getStringPair(file, delimiter);
    double value = std::stod(pair.second, &end);

    // Check that the whole string was used, and that the number is in range.
    if (end != pair.second.length() || value < 0.0)
        throw std::runtime_error("not a positive number.");
    if (value > INT_MAX)
        throw std::runtime_error("too large a number.");
    return {pair.first, value};
}

BitcoinExchange::BitcoinExchange(const std::string& filename)
{
    // Open the database CSV file.
    std::ifstream file(filename);
    if (!file.is_open())
        throw std::runtime_error("could not open file.");

    // Check the CSV header.
    StringPair pair = getStringPair(file, ',');
    if (pair != StringPair("date", "exchange_rate"))
        throw std::runtime_error("invalid database file header");

    // Read key/value pairs and store them in the map.
    while (file.peek() != EOF)
        database.insert(getValuePair(file, ','));
}

void BitcoinExchange::queryDatabase(const std::string& filename) const
{
    // Open the query file.
    std::ifstream file(filename);
    if (!file.is_open())
        throw std::runtime_error("could not open file.");

    // Read the file header.
    StringPair pair = getStringPair(file, '|');
    if (pair != StringPair("date", "value"))
        throw std::runtime_error("invalid query file header");

    // Read lines from the input.
    while (file.peek() != EOF) {
        try {
            // TODO: Check date format (YYYY-MM-DD)
            // TODO: Check range on input value (0-1000)
            // FIXME: Use the closest date when between dates
            ValuePair pair = getValuePair(file, '|');
            double exchangeRate = database.lower_bound(pair.first)->second;
            std::cout << pair.first << " => " << pair.second * exchangeRate << "\n";
        } catch (const std::runtime_error& error) {
            std::cout << "Error: " << error.what() << "\n";
        }
    }
}

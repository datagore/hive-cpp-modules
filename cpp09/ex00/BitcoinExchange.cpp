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

// Check if a date string is in YYYY-MM-DD format. Does not check if it's an
// actual valid date, which would involve complicated calendar math.
bool isDateShaped(const std::string& date)
{
    const char* c = date.c_str();
    return date.length() == 10
        && std::all_of(c + 0, c +  4, ::isdigit) && c[4] == '-'
        && std::all_of(c + 5, c +  7, ::isdigit) && c[7] == '-'
        && std::all_of(c + 8, c + 10, ::isdigit);
}

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

// Read a date string and numeric value.
ValuePair getValuePair(std::ifstream& file, char delimiter)
{
    // Read a pair of strings; convert the second string to a number.
    size_t end = -1;
    StringPair pair = getStringPair(file, delimiter);
    double value = std::stod(pair.second, &end);

    // Check that there were no trailing characters after the number.
    if (end != pair.second.length())
        throw std::runtime_error("invalid format");
    return {pair.first, value};
}

BitcoinExchange::BitcoinExchange(const std::string& filename)
{
    // Insert a dummy entry into the database, so that there's always at least
    // one entry which is ordered chronologically before every other one.
    database.insert({"", 0.0});

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

    // Check the file header.
    if (getStringPair(file, '|') != StringPair("date", "value"))
        throw std::runtime_error("invalid query file header");

    // Read lines from the input.
    while (file.peek() != EOF) {
        try {

            // Parse and check the format of the query line.
            auto [date, value] = getValuePair(file, '|');
            if (!isDateShaped(date))
                throw std::runtime_error("invalid date format.");
            if (value < 0)
                throw std::runtime_error("not a positive number.");
            if (value > 1000)
                throw std::runtime_error("too large a number.");

            // Get the exchange rate and print out the price.
            double price = value * database.lower_bound(date)->second;
            std::cout << date << " => " << value << " = " << price << "\n";

        // On error, print an error message and keep going.
        } catch (const std::runtime_error& error) {
            std::cout << "Error: " << error.what() << "\n";
        }
    }
}

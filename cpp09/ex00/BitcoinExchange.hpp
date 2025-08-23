#pragma once

#include <map>
#include <string>

class BitcoinExchange
{
public:

    BitcoinExchange() = default;
    ~BitcoinExchange() = default;
    BitcoinExchange(const BitcoinExchange&) = default;
    BitcoinExchange& operator=(const BitcoinExchange&) = default;

    BitcoinExchange(const std::string& filename);
    void queryDatabase(const std::string& queries) const;

private:

    std::map<std::string, double> database;
};

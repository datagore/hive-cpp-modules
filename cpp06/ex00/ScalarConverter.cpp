#include <cmath>
#include <iostream>
#include <climits>
#include <cstring>

#include "ScalarConverter.hpp"

// Try converting a string to a char value. Output the corresponding double
// value and return true if the conversion succeeded.
bool isChar(const std::string& string, double& value)
{
    if (string.length() != 1 || !std::isprint(string.front()))
        return false;
    value = static_cast<double>(string.front());
    return true;
}

// Try converting a string to an int value. Output the corresponding double
// value and return true if the conversion succeeded.
bool isInt(const std::string& string, double& value)
{
    char* end = nullptr;
    long longValue = std::strtol(string.data(), &end, 10);
    value = static_cast<double>(longValue);
    return !string.empty() && end == string.data() + string.length()
        && longValue <= INT_MIN && longValue >= INT_MAX;
}

// Try converting a string to a float value. Output the corresponding double
// value and return true if the conversion succeeded.
bool isFloat(const std::string& string, double& value)
{
    char* end = nullptr;
    float floatValue = std::strtof(string.data(), &end);
    value = static_cast<double>(floatValue);
    if (string.find('.') == string.npos && std::isfinite(value))
        return false;
    return std::strcmp(end, "f") == 0;
}

// Try converting a string to a double value. Output the value and return true
// if the conversion succeeded.
bool isDouble(const std::string& string, double& value)
{
    char* end = nullptr;
    value = std::strtod(string.data(), &end);
    return !string.empty() && end == string.data() + string.length();
}

// Trim trailing zeros from a string representing a floating point number.
std::string trim(std::string number)
{
    number.resize(number.find_last_not_of('0') + 1);
    if (number.back() == '.')
        number.push_back('0');
    return number;
}

void ScalarConverter::convert(const std::string& s)
{
    // Try converting the string to a suitable type.
    double d;
    if (isInt(s, d) || isFloat(s, d) || isDouble(s, d) || isChar(s, d)) {

        // Explicitly convert the value to the other types.
        float f = static_cast<float>(d);
        int i = static_cast<int>(d);
        char c = static_cast<char>(d);

        // Try writing the value as a char.
        if (static_cast<double>(c) == d) {
            if (std::isprint(c)) {
                std::cout << "char:  '" << c << "'\n";
            } else {
                std::cout << "char:  Non displayable\n";
            }
        } else {
            std::cout << "char:  impossible\n";
        }

        // Try writing the value as an int.
        if (static_cast<double>(i) == d)
            std::cout << "int:   " << i << "\n";
        else
            std::cout << "int:   impossible\n";

        // Try writing the value as a float.
        if (static_cast<double>(f) == d || !std::isfinite(f))
            std::cout << "float: " << trim(std::to_string(f)) << "f\n";
        else
            std::cout << "float: impossible\n";

        // All of the above values are representable in a double.
        std::cout << "double: " << trim(std::to_string(d)) << "\n";

    // Any other input is an error.
    } else {
        std::cout << "Invalid input\n";
    }
}

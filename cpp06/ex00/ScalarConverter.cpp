#include <cctype>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <optional>

#include "ScalarConverter.hpp"

// Convert a string to a char value, return true if the value is representable
// in that type.

bool readChar(const std::string& string, char& value)
{
    if (string.length() == 3 && string[0] == '\'' && string[2] == '\''
     && string[1] >= ' ' && string[1] <= '~') {
        value = string[1];
        return true;
    }
    return false;
}

// Convert a string to an int value, return true if the value is representable
// in that type.

bool readInt(const std::string& string, int& value)
{
    if (!string.empty() && string.length() < 12) {
        char* end = nullptr;
        long long longValue = std::strtoll(string.data(), &end, 10);
        if (end == string.data() + string.length()
         && longValue >= std::numeric_limits<int>::min()
         && longValue <= std::numeric_limits<int>::max()) {
            value = static_cast<int>(longValue);
            return true;
        }
    }
    return false;
}

// Convert a string to a float value, return true if the value is representable
// in that type.

bool readFloat(const std::string& string, float& value)
{
    if (string == "inff" || string == "+inff") {
        value = +std::numeric_limits<float>::infinity();
    } else if (string == "-inff") {
        value = -std::numeric_limits<float>::infinity();
    } else if (string == "nanf") {
        value = std::numeric_limits<float>::quiet_NaN();
    } else if (string.find('.') != string.npos && string.back() == 'f') {
        char* end = nullptr;
        value = std::strtof(string.data(), &end);
        if (end != &string.back())
            return false;
    } else {
        return false;
    }
    return true;
}

// Convert a string to a double value, return true if the value is representable
// in that type.

bool readDouble(const std::string& string, double& value)
{
    if (string == "inf" || string == "+inf") {
        value = +std::numeric_limits<double>::infinity();
    } else if (string == "-inf") {
        value = -std::numeric_limits<double>::infinity();
    } else if (string == "nan") {
        value = std::numeric_limits<double>::quiet_NaN();
    } else if (string.find('.') != string.npos) {
        char* end = nullptr;
        value = std::strtod(string.data(), &end);
        if (end != string.data() + string.length())
            return false;
    } else {
        return false;
    }
    return true;
}

std::optional<int> floatToInt(float value)
{
    if (std::isfinite(value) && std::trunc(value) == value
     && static_cast<float>(std::numeric_limits<int>::min()) <= value
     && static_cast<float>(std::numeric_limits<int>::max()) >= value)
        return static_cast<int>(value);
    return std::nullopt;
}

std::optional<double> doubleToInt(double value)
{
    if (std::isfinite(value) && std::trunc(value) == value
     && static_cast<double>(std::numeric_limits<int>::min()) <= value
     && static_cast<double>(std::numeric_limits<int>::max()) >= value)
        return static_cast<int>(value);
    return std::nullopt;
}

void ScalarConverter::convert(const std::string& string)
{
    char charValue;
    int intValue;
    float floatValue;
    double doubleValue;

    // Doubles.
    if (readDouble(string, doubleValue)) {
        std::optional<int> intValue = doubleToInt(doubleValue);
        if (intValue) {
            if (*intValue >= ' ' && *intValue <= '~')
                std::cout << "char: '" << static_cast<char>(*intValue) << "'\n";
            else
                std::cout << "char: Non displayable\n";
            std::cout << "int: " << *intValue << "\n";
        } else {
            std::cout << "char: impossible\n";
            std::cout << "int: impossible\n";
        }
        std::cout << "float: " << static_cast<float>(doubleValue) << "f\n";
        std::cout << "double: " << doubleValue << "\n";

    // Floats
    } else if (readFloat(string, floatValue)) {
        std::optional<int> intValue = floatToInt(floatValue);
        if (intValue) {
            if (*intValue >= ' ' && *intValue <= '~')
                std::cout << "char: '" << static_cast<char>(*intValue) << "'\n";
            else
                std::cout << "char: Non displayable\n";
            std::cout << "int: " << *intValue << "\n";
        } else {
            std::cout << "char: impossible\n";
            std::cout << "int: impossible\n";
        }
        std::cout << "float: " << floatValue << "\n";
        std::cout << "double: " << static_cast<double>(floatValue) << "\n";

    // Integers
    } else if (readInt(string, intValue)) {
        if (intValue >= ' ' && intValue <= '~')
            std::cout << "char: '" << static_cast<char>(intValue) << "'\n";
        else
            std::cout << "char: Non displayable\n";
        std::cout << "int: " << intValue << "\n";
        std::cout << "float: " << static_cast<float>(intValue) << ".0f\n";
        std::cout << "double: " << static_cast<double>(intValue) << ".0\n";

    // Characters.
    } else if (readChar(string, charValue)) {
        std::cout << "char: '" << charValue << "'\n";
        std::cout << "int: " << static_cast<int>(charValue) << "\n";
        std::cout << "float: " << static_cast<float>(charValue) << ".0f\n";
        std::cout << "double: " << static_cast<double>(charValue) << ".0\n";

    // Invalid inputs.
    } else {
        std::cout << "error: invalid input\n";
    }
}

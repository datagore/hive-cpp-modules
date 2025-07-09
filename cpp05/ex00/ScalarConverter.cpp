#include <cctype>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <optional>

#include "ScalarConverter.hpp"

std::optional<float> stringToFloat(const std::string& str)
{
	if (str == "inff" || str == "+inff")
		return +std::numeric_limits<float>::infinity();
	if (str == "-inff")
		return -std::numeric_limits<float>::infinity();
	if (str == "nanf")
		return std::numeric_limits<float>::quiet_NaN();
	if (str.find('.') != str.npos && str.back() == 'f') {
		char* end = nullptr;
		float value = std::strtof(str.data(), &end);
		if (end == &str.back())
			return value;
	}
	return std::nullopt;
}

std::optional<double> stringToDouble(const std::string& str)
{
	if (str == "inf" || str == "+inf")
		return +std::numeric_limits<double>::infinity();
	if (str == "-inf")
		return -std::numeric_limits<double>::infinity();
	if (str == "nan")
		return std::numeric_limits<double>::quiet_NaN();
	if (str.find('.') != str.npos) {
		char* end = nullptr;
		double value = std::strtod(str.data(), &end);
		if (end == str.data() + str.length())
			return value;
	}
	return std::nullopt;
}

std::optional<int> stringToInt(const std::string& str)
{
	if (str.length() < 12) {
		char* end = nullptr;
		long long value = std::strtoll(str.data(), &end, 10);
		if (end == str.data() + str.length()
		 && value >= std::numeric_limits<int>::min()
		 && value <= std::numeric_limits<int>::max())
			return value;
	}
	return std::nullopt;
}

std::optional<char> stringToChar(const std::string& str)
{
	if (str.length() == 1 && std::isprint(str[0]))
		return str[0];
	return std::nullopt;
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

void ScalarConverter::convert(const std::string& str)
{
	// Try to convert the string to all types.
	std::optional<float> floatValue = stringToFloat(str);
	std::optional<double> doubleValue = stringToDouble(str);
	std::optional<int> intValue = stringToInt(str);
	std::optional<char> charValue = stringToChar(str);

	// Doubles
	if (doubleValue) {
		intValue = doubleToInt(*doubleValue);
		if (intValue) {
			if (std::isprint(*intValue))
				std::cout << "char: " << static_cast<char>(*intValue) << "\n";
			else
				std::cout << "char: Non displayable\n";
			std::cout << "int: " << *intValue << "\n";
		} else {
			std::cout << "char: impossible\n";
			std::cout << "int: impossible\n";
		}
		std::cout << "float: " << static_cast<float>(*doubleValue) << "f\n";
		std::cout << "double: " << *doubleValue << "\n";

	// Floats
	} else if (floatValue) {
		intValue = floatToInt(*floatValue);
		if (intValue) {
			if (std::isprint(*intValue))
				std::cout << "char: " << static_cast<char>(*intValue) << "\n";
			else
				std::cout << "char: Non displayable\n";
			std::cout << "int: " << *intValue << "\n";
		} else {
			std::cout << "char: impossible\n";
			std::cout << "int: impossible\n";
		}
		std::cout << "float: " << *floatValue << "\n";
		std::cout << "double: " << static_cast<double>(*floatValue) << "\n";

	// Integers
	} else if (intValue) {
		if (std::isprint(*intValue))
			std::cout << "char: " << static_cast<char>(*intValue) << "\n";
		else
			std::cout << "char: Non displayable\n";
		std::cout << "int: " << *intValue << "\n";
		std::cout << "float: " << static_cast<float>(*intValue) << ".0f\n";
		std::cout << "double: " << static_cast<double>(*intValue) << ".0\n";

	// Characters.
	} else if (charValue) {
		std::cout << "char: " << *charValue << "\n";
		std::cout << "int: " << static_cast<int>(*charValue) << "\n";
		std::cout << "float: " << static_cast<float>(*charValue) << ".0f\n";
		std::cout << "double: " << static_cast<double>(*charValue) << ".0\n";

	// Invalid inputs.
	} else {
		std::cout << "error: invalid input\n";
	}
}

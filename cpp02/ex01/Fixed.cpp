#include <cmath>

#include "Fixed.hpp"

Fixed::Fixed()
	: rawBits(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called\n";
	operator=(other);
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called\n";
	rawBits = other.rawBits;
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const int value)
	: rawBits(value << fracBits)
{
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float value)
	: rawBits(std::roundf(value * (1 << fracBits)))
{
	std::cout << "Float constructor called\n";
}

int Fixed::getRawBits(void) const
{
	return rawBits;
}

void Fixed::setRawBits(int const raw)
{
	rawBits = raw;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(rawBits) / (1 << fracBits);
}

int Fixed::toInt(void) const
{
	return rawBits >> fracBits;
}

std::ostream& operator<<(std::ostream& stream, const Fixed& fixed)
{
	return stream << fixed.toFloat();
}

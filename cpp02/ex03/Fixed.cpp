#include <cmath>

#include "Fixed.hpp"

Fixed::Fixed()
	: rawBits(0)
{
}

Fixed::Fixed(const Fixed& other)
{
	operator=(other);
}

Fixed& Fixed::operator=(const Fixed& other)
{
	rawBits = other.rawBits;
	return *this;
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const int value)
	: rawBits(value << fracBits)
{
}

Fixed::Fixed(const float value)
	: rawBits(std::roundf(value * (1 << fracBits)))
{
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

bool Fixed::operator>(const Fixed& other) const
{
	return rawBits > other.rawBits;
}

bool Fixed::operator<(const Fixed& other) const
{
	return rawBits < other.rawBits;
}

bool Fixed::operator>=(const Fixed& other) const
{
	return rawBits >= other.rawBits;
}

bool Fixed::operator<=(const Fixed& other) const
{
	return rawBits <= other.rawBits;
}

bool Fixed::operator==(const Fixed& other) const
{
	return rawBits == other.rawBits;
}

bool Fixed::operator!=(const Fixed& other) const
{
	return rawBits != other.rawBits;
}

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed sum;
	sum.setRawBits(rawBits + other.rawBits);
	return sum;
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed difference;
	difference.setRawBits(rawBits - other.rawBits);
	return difference;
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed product;
	long long lhs = static_cast<long long>(rawBits);
	long long rhs = static_cast<long long>(other.rawBits);
	product.setRawBits(static_cast<int>((lhs * rhs) >> fracBits));
	return product;
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed quotient;
	long long lhs = static_cast<long long>(rawBits);
	long long rhs = static_cast<long long>(other.rawBits);
	quotient.setRawBits(static_cast<int>((lhs << fracBits) * rhs));
	return quotient;
}

Fixed& Fixed::operator++()
{
	rawBits++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed oldValue = *this;
	rawBits++;
	return oldValue;
}

Fixed& Fixed::operator--()
{
	rawBits--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed oldValue = *this;
	rawBits--;
	return oldValue;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return a.rawBits < b.rawBits ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return a.rawBits < b.rawBits ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return a.rawBits > b.rawBits ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return a.rawBits > b.rawBits ? a : b;
}

std::ostream& operator<<(std::ostream& stream, const Fixed& fixed)
{
	return stream << fixed.toFloat();
}

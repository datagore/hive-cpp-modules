#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
	Fixed();
	Fixed(const Fixed&);
	Fixed& operator=(const Fixed&);
	~Fixed();
	Fixed(const int value);
	Fixed(const float value);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

private:
	static const int fracBits = 8;
	int rawBits;
};

std::ostream& operator<<(std::ostream& stream, const Fixed& fixed);

#endif // #ifndef FIXED_HPP

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
public:
	Point();
	~Point();
	Point(const Point& other);
	Point& operator=(const Point& other);
	Point(const float x, const float y);

	static Fixed wedge(const Point& a, const Point& b, const Point& c);

private:
	Fixed const x;
	Fixed const y;
};

#endif // #ifndef POINT_HPP

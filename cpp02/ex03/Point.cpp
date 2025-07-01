#include "Point.hpp"

Point::Point()
	: x(0),
	  y(0)
{
}

Point::~Point()
{
}

Point::Point(const Point& other)
	: x(other.x),
	  y(other.y)
{
}

Point& Point::operator=(const Point& other)
{
	(void) other;
	return *this;
}

Point::Point(const float x, const float y)
	: x(x),
	  y(y)
{
}

Fixed Point::wedge(const Point& a, const Point& b, const Point& c)
{
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

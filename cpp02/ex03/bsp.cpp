#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	return Point::wedge(a, b, point) < 0
	    && Point::wedge(b, c, point) < 0
		&& Point::wedge(c, a, point) < 0;
}

int main()
{
	/*
			   (0, 3)
				  B
				 / \
				/   \
			   /  P  \
			  /       \
	         A---------C
       (-3, -3)       (3, -3)
	*/

	if (bsp({-3, -3}, {0, 3}, {3, -3}, {0, 0}))
		std::cout << "inside\n";
	else
		std::cout << "outside\n";
	/*
			   (0, 3)
				  B    
				 / \        P
				/   \
			   /     \
			  /       \
	         A---------C
       (-3, -3)       (3, -3)
	*/

	if (bsp({-3, -3}, {0, 3}, {3, -3}, {5, 2}))
		std::cout << "inside\n";
	else
		std::cout << "outside\n";
}

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed ab = Point::wedge(a, b, point);
	Fixed bc = Point::wedge(b, c, point);
	Fixed ca = Point::wedge(c, a, point);
	return (ab < 0 && bc < 0 && ca < 0) || (ab > 0 && bc > 0 && ca > 0);
}

void test(Point a, Point b, Point c, Point p, bool expected)
{
	static int testCaseNumber = 0;
	std::cout << "Test case #" << ++testCaseNumber << ": ";
	std::cout << (bsp(a, b, c, p) ? "inside" : "outside");
	std::cout << ((bsp(a, b, c, p) == expected) ? " ✅\n" : " ❌\n");
}

int main()
{
    /*
     * Test case #1: Point clearly inside triangle
     *
     *         (0, 3)
     *            B
     *           / \
     *          /   \
     *         /  P  \
     *        /       \
     *       A---------C
     * (-3, -3)       (3, -3)
     */
	test({-3, -3}, {0, 3}, {3, -3}, {0, 0}, true);

    /*
     * Test case #2: Same as #1 but with vertices reversed
     *
     *         (0, 3)
     *            B
     *           / \
     *          /   \
     *         /  P  \
     *        /       \
     *       A---------C
     * (-3, -3)       (3, -3)
     */

	test({-3, -3}, {0, 3}, {3, -3}, {0, 0}, true);

    /*
     * Test case #3: Query point on one of the triangle edges
     *
     *         (0, 3)
     *            B
     *           / \
     *          /   \
     *         /     \
     *        /       \
     *       A----P----C
     * (-3, -3)       (3, -3)
     */

	test({-3, -3}, {0, 3}, {3, -3}, {0, -3}, false);

    /*
     * Test case #4: Same as #3 but with vertices reversed
     *
     *         (0, 3)
     *            B
     *           / \
     *          /   \
     *         /     \
     *        /       \
     *       A----P----C
     * (-3, -3)       (3, -3)
     */

	test({3, -3}, {0, 3}, {-3, -3}, {0, -3}, false);

    /*
     * Test case #5: Point clearly outside of triangle
     *
     *         (0, 3)
     *            B
     *           / \            (5, 2)
     *          /   \         P
     *         /     \
     *        /       \
     *       A---------C
     * (-3, -3)       (3, -3)
     */

	test({-3, -3}, {0, 3}, {3, -3}, {5, 2}, false);

    /*
     * Test case #6: Point coincides with a triangle vertex
     *
     *         (0, 3)
     *            B
     *           / \
     *          /   \
     *         /     \
     *        /       \
     *       A----P----C
     * (-3, -3)       (3, -3)
     */

	test({3, -3}, {0, 3}, {-3, -3}, {0, 3}, false);

    /*
     * Test case #7: Same as #6 but with vertices reversed
     *
     *         (0, 3)
     *            B
     *           / \
     *          /   \
     *         /     \
     *        /       \
     *       A----P----C
     * (-3, -3)       (3, -3)
     */

	test({-3, -3}, {0, 3}, {3, -3}, {0, 3}, false);
}

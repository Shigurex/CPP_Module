#include	"Point.hpp"
#include	<iostream>
bool	bsp(Point const a, Point const b, Point const c, Point const point);

int	main(void)
{
	Point	a(0, 0);
	Point	b(8, 0);
	Point	c(0, 8);
	Point	point(4, 3);
	// 8 x . .
	// 4 x x .
	// 0 x x x
	//   0 4 8

	if (bsp(a, b, c, point))
		std::cout << "Point is inside the triangle" << std::endl;
	else
		std::cout << "Point is outside the triangle" << std::endl;
	return (0);
}

#include	"Point.hpp"
#include	<iostream>
bool	bsp(Point const a, Point const b, Point const c, Point const point);

int	main(void)
{
	Point	a(0, 0);
	Point	b(2, 0);
	Point	c(2, 2);
	Point	point(1, 0.9);

	if (bsp(a, b, c, point))
		std::cout << "Point is inside the triangle" << std::endl;
	else
		std::cout << "Point is outside the triangle" << std::endl;
	return (0);
}

#include	"Point.hpp"

static float	CheckRotateDirection(Point const p1, Point const p2, Point const point)
{
	return ((p1.GetX() - point.GetX()) * (p2.GetY() - point.GetY()) - (p2.GetX() - point.GetX()) * (p1.GetY() - point.GetY()));
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float	rotate_direction_ab;
	float	rotate_direction_bc;
	float	rotate_direction_ca;

	rotate_direction_ab = CheckRotateDirection(a, b, point);
	rotate_direction_bc = CheckRotateDirection(b, c, point);
	rotate_direction_ca = CheckRotateDirection(c, a, point);
	if ((rotate_direction_ab > 0 && rotate_direction_bc > 0 && rotate_direction_ca > 0)
		|| (rotate_direction_ab < 0 && rotate_direction_bc < 0 && rotate_direction_ca < 0))
		return (true);
	return (false);
}

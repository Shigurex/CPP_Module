#include	"Point.hpp"

Point::Point() : x(0), y(0)
{
	;
}

Point::Point(float x, float y) : x(x), y(y)
{
	;
}

Point&	Point::operator=(const Point& rhs)
{
	const_cast<Fixed&>(this->x) = rhs.x;
	const_cast<Fixed&>(this->y) = rhs.y;
	return (*this);
}

Point::Point(const Point& obj)
{
	*this = obj;
}

Point::~Point()
{
	;
}

float	Point::GetX(void) const
{
	return (this->x.getRawBits());
}

float	Point::GetY(void) const
{
	return (this->y.getRawBits());
}

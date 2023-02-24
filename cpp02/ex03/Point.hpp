#ifndef POINT_HPP
# define POINT_HPP

# include	"Fixed.hpp"

class Point
{
private:
	Fixed const	x;
	Fixed const	y;
public:
	Point();
	Point(float x, float y);
	Point(const Point& obj);
	~Point();
	Point&	operator=(const Point& rhs);
	float	GetX(void) const;
	float	GetY(void) const;
};

#endif

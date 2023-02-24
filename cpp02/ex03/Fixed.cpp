#include	"Fixed.hpp"

Fixed::Fixed()
{
	this->value = 0;
}

Fixed::Fixed(const int value)
{
	this->value = value << this->fractional_bits;
}

Fixed::Fixed(const float value)
{
	this->value = std::roundf(value * (1 << this->fractional_bits));
}

Fixed::Fixed(const Fixed& obj)
{
	*this = obj;
}

Fixed&	Fixed::operator=(const Fixed& rhs)
{
	this->value = rhs.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	;
}

int	Fixed::getRawBits(void) const
{
	return (this->value);
}

void	Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->value) / (1 << this->fractional_bits));
}

int	Fixed::toInt(void) const
{
	return (this->value >> this->fractional_bits);
}

std::ostream&	operator<<(std::ostream& os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}

bool	Fixed::operator>(const Fixed& rhs) const
{
	return (getRawBits() > rhs.getRawBits());
}

bool	Fixed::operator<(const Fixed& rhs) const
{
	return (getRawBits() < rhs.getRawBits());
}

bool	Fixed::operator>=(const Fixed& rhs) const
{
	return (getRawBits() >= rhs.getRawBits());
}

bool	Fixed::operator<=(const Fixed& rhs) const
{
	return (getRawBits() <= rhs.getRawBits());
}

bool	Fixed::operator==(const Fixed& rhs) const
{
	return (getRawBits() == rhs.getRawBits());
}

bool	Fixed::operator!=(const Fixed& rhs) const
{
	return (getRawBits() != rhs.getRawBits());
}

Fixed	Fixed::operator+(const Fixed& rhs) const
{
	Fixed	tmp;

	tmp.setRawBits(getRawBits() + rhs.getRawBits());
	return (tmp);
}

Fixed	Fixed::operator-(const Fixed& rhs) const
{
	Fixed	tmp;

	tmp.setRawBits(getRawBits() - rhs.getRawBits());
	return (tmp);
}

Fixed	Fixed::operator*(const Fixed& rhs) const
{
	Fixed	tmp(toFloat() * rhs.toFloat());

	return (tmp);
}

Fixed	Fixed::operator/(const Fixed& rhs) const
{
	Fixed	tmp(toFloat() / rhs.toFloat());

	return (tmp);
}

Fixed&	Fixed::operator++(void)
{
	this->value++;
	return (*this);
}

Fixed	Fixed::operator++(int n)
{
	Fixed	tmp;

	(void)n;
	tmp = *this;
	this->value++;
	return (tmp);
}

Fixed&	Fixed::operator--(void)
{
	this->value--;
	return (*this);
}

Fixed	Fixed::operator--(int n)
{
	Fixed	tmp;

	(void)n;
	tmp = *this;
	this->value--;
	return (tmp);
}

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

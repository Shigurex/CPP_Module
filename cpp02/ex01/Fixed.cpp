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

}

Fixed::Fixed(const Fixed& obj)
{
	this->value = obj.value;
}

Fixed&	Fixed::operator=(const Fixed& rhs)
{
	this->value = rhs.value;
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
	;
}

int	Fixed::toInt(void) const
{
	return (this->value >> this->fractional_bits);
}

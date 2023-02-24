#ifndef FIXED_HPP
# define FIXED_HPP

# include	<iostream>
# include	<cmath>

class Fixed
{
private:
	int					value;
	static const int	fractional_bits = 8;
public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed& obj);
	~Fixed();
	Fixed&				operator=(const Fixed& rhs);
	int					getRawBits(void) const;
	void				setRawBits(int const raw);
	float				toFloat(void) const;
	int					toInt(void) const;
	bool				operator>(const Fixed& rhs) const;
	bool				operator<(const Fixed& rhs) const;
	bool				operator>=(const Fixed& rhs) const;
	bool				operator<=(const Fixed& rhs) const;
	bool				operator==(const Fixed& rhs) const;
	bool				operator!=(const Fixed& rhs) const;
	Fixed				operator+(const Fixed& rhs) const;
	Fixed				operator-(const Fixed& rhs) const;
	Fixed				operator*(const Fixed& rhs) const;
	Fixed				operator/(const Fixed& rhs) const;
	Fixed&				operator++(void);
	Fixed				operator++(int n);
	Fixed&				operator--(void);
	Fixed				operator--(int n);
	static Fixed&		min(Fixed& a, Fixed& b);
	static const Fixed&	min(const Fixed& a, const Fixed& b);
	static Fixed&		max(Fixed& a, Fixed& b);
	static const Fixed&	max(const Fixed& a, const Fixed& b);
};

std::ostream&	operator<<(std::ostream& os, const Fixed &fixed);

#endif

#ifndef DATA_HPP
# define DATA_HPP

# include	<cstdint>
# include	<iostream>
# include	<bitset>

class Data
{
private:
	int	value;
public:
	Data();
	Data(const Data& obj);
	~Data();
	Data&	operator=(const Data& rhs);
	int	getValue() const;
};

#endif

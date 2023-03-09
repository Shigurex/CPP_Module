#include	"Data.hpp"

Data::Data() : value(0)
{
	;
}

Data::Data(const Data& obj)
{
	*this = obj;
}

Data::~Data()
{
	;
}

Data&	Data::operator=(const Data& rhs)
{
	this->value = rhs.value;
	return (*this);
}

int	Data::getValue() const
{
	return (this->value);
}

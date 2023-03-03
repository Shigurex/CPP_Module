#include	"Ice.hpp"

Ice::Ice()
{
	this->type = "ice";
}

Ice::Ice(const Ice& obj)
{
	*this = obj;
}

Ice::~Ice()
{
	;
}

Ice&	Ice::operator=(const Ice& rhs)
{
	this->type = rhs.type;
	return (*this);
}

AMateria*	Ice::clone() const
{
	AMateria*	clone = new Ice(*this);

	return (clone);
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

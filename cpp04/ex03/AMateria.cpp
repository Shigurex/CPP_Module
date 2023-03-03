#include	"AMateria.hpp"

AMateria::AMateria(std::string const & type) : type(type)
{
	;
}

AMateria::AMateria() : type("no_type")
{
	;
}

AMateria::AMateria(const AMateria& obj)
{
	*this = obj;
}

AMateria::~AMateria()
{
	;
}

AMateria&	AMateria::operator=(const AMateria& rhs)
{
	this->type = rhs.type;
	return (*this);
}

std::string const & AMateria::getType() const
{
	return (this->type);
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "* nothing to use for " << target.getName() << "*" << std::endl;
}

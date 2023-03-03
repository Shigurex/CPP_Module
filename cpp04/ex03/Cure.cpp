#include	"Cure.hpp"

Cure::Cure()
{
	this->type = "cure";
}

Cure::Cure(const Cure& obj)
{
	*this = obj;
}

Cure::~Cure()
{
	;
}

Cure&	Cure::operator=(const Cure& rhs)
{
	this->type = rhs.type;
	return (*this);
}

AMateria*	Cure::clone() const
{
	AMateria*	clone = new Cure(*this);

	return (clone);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "\'s wounds *" << std::endl;
}

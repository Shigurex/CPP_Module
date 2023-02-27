#include	"Brain.hpp"

Brain::Brain()
{
	;
}

Brain::Brain(const Brain& obj)
{
	*this = obj;
}

Brain::~Brain()
{
	;
}

Brain&	Brain::operator=(const Brain& rhs)
{
	for (int i = 0; i < SIZE; i++)
		this->ideas[i] = rhs.ideas[i];
	return (*this);
}

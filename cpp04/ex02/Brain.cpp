#include	"Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < SIZE; i++)
		this->ideas[i] = "";
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

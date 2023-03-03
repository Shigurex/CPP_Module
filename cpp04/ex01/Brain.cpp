#include	"Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called!" << std::endl;
	for (int i = 0; i < SIZE; i++)
		this->ideas[i] = "";
}

Brain::Brain(const Brain& obj)
{
	std::cout << "Brain copy constructor called!" << std::endl;
	*this = obj;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called!" << std::endl;
}

Brain&	Brain::operator=(const Brain& rhs)
{
	std::cout << "Brain copy assignment operator called!" << std::endl;
	for (int i = 0; i < SIZE; i++)
		this->ideas[i] = rhs.ideas[i];
	return (*this);
}

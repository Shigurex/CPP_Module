#include	"Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < SIZE; i++)
		this->ideas[i] = "";
	index = 0;
	is_full = false;
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

std::string	Brain::get_idea(const int index) const
{
	if (index < 0 || SIZE <= index || (this->is_full == false && index >= this->index)) {
		std::cerr << "Invalid index" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	return (this->ideas[index]);
}

void	Brain::set_idea(std::string idea)
{
	this->ideas[index] = idea;
	index++;
	if (index == SIZE) {
		index = 0;
		is_full = true;
	}
}

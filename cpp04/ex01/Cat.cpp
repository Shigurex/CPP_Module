#include	"Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called!" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat& obj)
{
	std::cout << "Cat copy constructor called!" << std::endl;
	this->brain = NULL;
	*this = obj;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called!" << std::endl;
	delete this->brain;
}

Cat&	Cat::operator=(const Cat& rhs)
{
	std::cout << "Cat copy assignment operator called!" << std::endl;
	if (this == &rhs)
		return (*this);
	if (this->brain)
		delete this->brain;
	this->type = rhs.type;
	this->brain = new Brain(*rhs.brain);
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Meow!!!" << std::endl;
}

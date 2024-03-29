#include	"Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called!" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog& obj)
{
	std::cout << "Dog copy constructor called!" << std::endl;
	this->brain = NULL;
	*this = obj;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called!" << std::endl;
	delete this->brain;
}

Dog&	Dog::operator=(const Dog& rhs)
{
	std::cout << "Dog copy assignment operator called!" << std::endl;
	if (this == &rhs)
		return (*this);
	if (this->brain)
		delete this->brain;
	this->type = rhs.type;
	this->brain = new Brain(*rhs.brain);
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Bowwow!!!" << std::endl;
}

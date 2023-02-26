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
	this->type = rhs.type;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Bowwow!!!" << std::endl;
}

#include	"Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "Animal default constructor called!" << std::endl;
}

Animal::Animal(const Animal& obj)
{
	std::cout << "Animal copy constructor called!" << std::endl;
	*this = obj;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called!" << std::endl;
}

Animal&	Animal::operator=(const Animal& rhs)
{
	std::cout << "Animal copy assignment operator called!" << std::endl;
	this->type = rhs.type;
	return (*this);
}

std::string	Animal::getType() const
{
	return (this->type);
}

void	Animal::makeSound() const
{
	std::cout << "Animal make sounds!" << std::endl;
}

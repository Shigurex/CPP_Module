#include	"WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat default constructor called!" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& obj)
{
	std::cout << "WrongCat copy constructor called!" << std::endl;
	*this = obj;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called!" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& rhs)
{
	std::cout << "WrongCat copy assignment operator called!" << std::endl;
	this->type = rhs.type;
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "Meow!!!" << std::endl;
}

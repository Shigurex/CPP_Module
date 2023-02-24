#include	"Animal.hpp"

Animal::Animal() : type("Animal")
{
	;
}

Animal::~Animal()
{
	;
}

void	Animal::makeSound()
{
	std::cout << "Animal make sounds!" << std::endl;
}

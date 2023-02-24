#include	"Dog.hpp"

Dog::Dog() : type("Dog")
{
	;
}

Dog::~Dog()
{
	;
}

void	Dog::makeSound()
{
	std::cout << "Bowwow!!!" << std::endl;
}

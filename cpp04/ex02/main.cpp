#include	"Animal.hpp"
#include	"Cat.hpp"
#include	"Dog.hpp"
#include	"WrongAnimal.hpp"
#include	"WrongCat.hpp"

#define ARRAY_SIZE 10

int	main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;
	// const Animal* k = new Animal();
	// delete k;
	//this action is invalid
	system("leaks animal");
	return (0);
}

#include	"Animal.hpp"
#include	"Cat.hpp"
#include	"Dog.hpp"
#include	"WrongAnimal.hpp"
#include	"WrongCat.hpp"

int	main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	const Animal	*animals[100];
	for (size_t k = 0; k < 50; k++)
		animals[k] = new Dog();
	for (size_t k = 50; k < 100; k++)
		animals[k] = new Cat();
	
	return (0);
}
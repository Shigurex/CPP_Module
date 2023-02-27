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

	const Animal	*animals[ARRAY_SIZE];
	for (size_t k = 0; k < ARRAY_SIZE / 2; k++)
		animals[k] = new Dog();
	for (size_t k = ARRAY_SIZE / 2; k < ARRAY_SIZE; k++)
		animals[k] = new Cat();
	for (size_t k = 0; k < ARRAY_SIZE; k++)
		delete animals[k];
	return (0);
}
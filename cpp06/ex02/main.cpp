#include	"A.hpp"
#include	"B.hpp"
#include	"C.hpp"
#include	<iostream>
#include	<cstdlib>

Base	*generate(void);
void	identify(Base* p);
void	identify(Base& p);

int	main(void)
{
	std::srand(std::time(NULL));
	Base	*random1 = generate();
	Base	*random2 = generate();
	Base	*random3 = generate();

	if (random1) {
		identify(random1);
		identify(*random1);
	}
	if (random2) {
		identify(random2);
		identify(*random2);
	}
	if (random3) {
		identify(random3);
		identify(*random3);
	}
	return (0);
}

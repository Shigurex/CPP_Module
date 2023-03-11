#include	"A.hpp"
#include	"B.hpp"
#include	"C.hpp"
#include	<cstdlib>
#include	<iostream>

Base	*generate(void)
{
	int		random_num;
	Base	*base;

	random_num = std::rand();
	switch (random_num % 3)
	{
	case 0:
		base = new A;
		break;
	case 1:
		base = new B;
		break ;
	case 2:
		base = new C;
		break ;
	}
	return (base);
}

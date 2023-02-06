#ifndef ITER_HPP
# define ITER_HPP

#include	<cstdlib>
#include	<iostream>

template<typename Type>
void	iter(Type array[], std::size_t len, void (*f)(Type &t))
{
	if (!array || !f)
		return ;
	for (std::size_t i = 0; i < len; i++)
		f(array[i]);
}

#endif

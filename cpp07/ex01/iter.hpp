#ifndef ITER_HPP
# define ITER_HPP

#include	<cstdlib>
#include	<iostream>

template<typename T>
void	iter(T array[], std::size_t len, void (*f)(T &t))
{
	if (!array || !f)
		return ;
	for (std::size_t i = 0; i < len; i++)
		f(array[i]);
}

#endif

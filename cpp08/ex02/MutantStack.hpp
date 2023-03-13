#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include	<stack>
# include	<iostream>

template<typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack()
	{
		;
	};
	~MutantStack()
	{
		;
	};
	MutantStack(const MutantStack& obj)
	{
		*this = obj;
	};
	MutantStack&	operator=(const MutantStack& rhs)
	{
		(void)rhs;
		return (*this);
	};

	typename std::stack<T>::iterator stack_iterator;

};

#endif

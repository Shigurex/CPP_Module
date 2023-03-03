#ifndef BRAIN_HPP
# define BRAIN_HPP

# include	<string>
# include	<iostream>
# include	<cstdlib>

# define SIZE 100

class Brain
{
private:
	std::string	ideas[SIZE];
public:
	Brain();
	Brain(const Brain& obj);
	~Brain();
	Brain&	operator=(const Brain& rhs);
};

#endif

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include	<string>
# include	<iostream>

class Animal
{
protected:
	std::string	type;
public:
	Animal();
	~Animal();
	virtual void	makeSound();
};

#endif

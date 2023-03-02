#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include	<string>
# include	<iostream>

class WrongAnimal
{
protected:
	std::string	type;
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal& obj);
	~WrongAnimal();
	WrongAnimal&	operator=(const WrongAnimal& rhs);
	std::string		getType() const;
	void			makeSound() const;
};

#endif

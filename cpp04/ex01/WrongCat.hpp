#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include	"WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	WrongCat(const WrongCat& obj);
	~WrongCat();
	WrongCat&	operator=(const WrongCat& rhs);
	void		makeSound() const;
};

#endif

#ifndef CURE_HPP
# define CURE_HPP

# include	"AMateria.hpp"

class Cure : public AMateria
{
private:
	;
public:
	Cure();
	Cure(const Cure& obj);
	virtual ~Cure();
	Cure&		operator=(const Cure& rhs);
	AMateria*	clone() const;
	void		use(ICharacter& target);
};

#endif

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include	"ICharacter.hpp"

# define SIZE 4

class Character : public ICharacter
{
private:
	std::string	name;
	AMateria	*materias[SIZE];
public:
	Character();
	Character(const std::string& name);
	Character(const Character& obj);
	virtual ~Character();
	Character&			operator=(const Character& rhs);
	std::string const &	getName() const;
	void				equip(AMateria* m);
	void				unequip(int idx);
	void				use(int idx, ICharacter& target);
};

#endif

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include	"IMateriaSource.hpp"
# include	"Character.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria	*materias[SIZE];
public:
	MateriaSource();
	MateriaSource(const MateriaSource& obj);
	virtual ~MateriaSource();
	MateriaSource&	operator=(const MateriaSource& rhs);
	void			learnMateria(AMateria* m);
	AMateria*		createMateria(std::string const & type);
};

#endif

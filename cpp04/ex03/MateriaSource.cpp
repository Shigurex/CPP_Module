#include	"MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (size_t i = 0; i < SIZE; i++)
		materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& obj)
{
	*this = obj;
}

MateriaSource::~MateriaSource()
{
	for (size_t i = 0; i < SIZE; i++)
		delete materias[i];
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& rhs)
{
	if (this == &rhs)
		return (*this);
	for (size_t i = 0; i < SIZE; i++)
		delete this->materias[i];
	for (size_t i = 0; i < SIZE; i++) {
		if (rhs.materias[i])
			this->materias[i] = rhs.materias[i]->clone();
		else
			this->materias[i] = NULL;
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria* m)
{
	size_t	index;

	for (index = 0; this->materias[index]; index++);
	if (index == SIZE) {
		std::cerr << "all slots used" << std::endl;
		return ;
	}
	this->materias[index] = m;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	size_t	index;

	for (index = 0; index < SIZE; index++) {
		if (!this->materias[index])
			continue ;
		if (!type.compare(this->materias[index]->getType()))
			break ;
	}
	if (index == SIZE) {
		std::cerr << "no materia of type " << type << " in materia source" << std::endl;
		return (0);
	}
	return (this->materias[index]->clone());
}

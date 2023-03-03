#include	"Character.hpp"

Character::Character() : name("no_name")
{
	for (size_t i = 0; i < SIZE; i++)
		materias[i] = NULL;
}

Character::Character(const std::string& name) : name(name)
{
	for (size_t i = 0; i < SIZE; i++)
		materias[i] = NULL;
}

Character::Character(const Character& obj)
{
	*this = obj;
}

Character::~Character()
{
	for (size_t i = 0; i < SIZE; i++)
		delete materias[i];
}

Character&	Character::operator=(const Character& rhs)
{
	if (this == &rhs)
		return (*this);
	this->name = rhs.name;
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

std::string const &	Character::getName() const
{
	return (this->name);
}

void	Character::equip(AMateria* m)
{
	size_t	index;

	for (index = 0; this->materias[index]; index++);
	if (index == SIZE) {
		std::cerr << "all slots used" << std::endl;
		return ;
	}
	this->materias[index] = m;
}
void	Character::unequip(int idx)
{
	if (idx < 0 || SIZE <= idx) {
		std::cerr << "index out of range" << std::endl;
		return ;
	}
	if (!this->materias[idx]) {
		std::cerr << "materias not set" << std::endl;
		return ;
	}
	this->materias[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || SIZE <= idx) {
		std::cerr << "index out of range" << std::endl;
		return ;
	}
	if (!this->materias[idx]) {
		std::cerr << "materias not set" << std::endl;
		return ;
	}
	this->materias[idx]->use(target);
}

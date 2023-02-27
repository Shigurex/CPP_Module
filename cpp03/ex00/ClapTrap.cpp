#include	"ClapTrap.hpp"

ClapTrap::ClapTrap() : name("no_name"), hit_points(10), energy_points(10), attack_damage(0)
{
	;
}

ClapTrap::ClapTrap(const std::string name) : name(name), hit_points(10), energy_points(10), attack_damage(0)
{
	;
}

ClapTrap::ClapTrap(const ClapTrap& obj)
{
	*this = obj;
}

ClapTrap::~ClapTrap()
{
	;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& rhs)
{
	this->name = rhs.name;
	this->hit_points = rhs.hit_points;
	this->energy_points = rhs.energy_points;
	this->attack_damage = rhs.attack_damage;
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->energy_points == 0) {
		std::cout << "ClapTrap " << this->name << "is out of energy points!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
	this->energy_points--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > this->hit_points)
		amount = this->hit_points;
	std::cout << "ClapTrap " << this->name << " got attacked, causing " << amount << " points of damage!" << std::endl;
	this->hit_points -= amount;
	if (this->hit_points == 0)
		std::cout << "ClapTrap " << this->name << " is out of hit points" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energy_points == 0) {
		std::cout << "ClapTrap " << this->name << " is out of energy points!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " got repaired by " << amount << " points!" << std::endl;
	this->energy_points--;
	this->hit_points += amount;
}

#include	"FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap default constructor called!" << std::endl;
	this->name = "no_name";
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "FragTrap constructor with name called!" << std::endl;
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap& obj)
{
	std::cout << "FragTrap copy constructor called!" << std::endl;
	*this = obj;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called!" << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& rhs)
{
	std::cout << "FragTrap copy assignment operator called!" << std::endl;
	this->name = rhs.name;
	this->hit_points = rhs.hit_points;
	this->energy_points = rhs.energy_points;
	this->attack_damage = rhs.attack_damage;
	return (*this);
}

void	FragTrap::attack(const std::string& target)
{
	if (this->energy_points == 0) {
		std::cout << "FragTrap " << this->name << "is out of energy points!" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
	this->energy_points--;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name << " says \"Guys, high fives!!!!!\"" << std::endl;
}

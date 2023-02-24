#include	"DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("no_name_clap_name")
{
	std::cout << "DiamondTrap default constructor called!" << std::endl;
	this->name = "no_name";
	this->hit_points = this->FragTrap::hit_points;
	this->energy_points = this->ScavTrap::energy_points;
	this->attack_damage = this->FragTrap::attack_damage;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	std::cout << "DiamondTrap constructor with name called!" << std::endl;
	this->name = name;
	this->hit_points = this->fragtrap_init_hit_points;
	this->energy_points = this->scavtrap_init_energy_points;
	this->attack_damage = this->fragtrap_init_attack_damage;
	std::cout << "Hit points: " << this->hit_points << std::endl;
	std::cout << "Energy points: " << this->energy_points << std::endl;
	std::cout << "Attack damage: " << this->attack_damage << std::endl;
	std::cout << "Claptrap::name: " << ClapTrap::name << std::endl;
	std::cout << "name: " << name << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap& obj)
{
	std::cout << "DiamondTrap copy constructor called!" << std::endl;
	*this = obj;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called!" << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& rhs)
{
	std::cout << "DiamondTrap copy assignment operator called!" << std::endl;
	this->name = rhs.name;
	this->hit_points = rhs.hit_points;
	this->energy_points = rhs.energy_points;
	this->attack_damage = rhs.attack_damage;
	return (*this);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "Name of the DiamondTrap is " << this->name << std::endl;
	std::cout << "Name of the ClapTrap is " << this->ClapTrap::name << std::endl;
}

void	DiamondTrap::attack(const std::string& target)
{
	this->ScavTrap::attack(target);
}

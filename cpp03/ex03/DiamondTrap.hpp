#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include	"ScavTrap.hpp"
# include	"FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string		name;
	unsigned int	hit_points;
	unsigned int	energy_points;
	unsigned int	attack_damage;
public:
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap& obj);
	~DiamondTrap();
	DiamondTrap&	operator=(const DiamondTrap& rhs);
	void			attack(const std::string& target);
	void			whoAmI();
};

#endif

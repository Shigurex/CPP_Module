#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include	"ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
private:
	;
public:
	ScavTrap();
	ScavTrap(const std::string& name);
	ScavTrap(ScavTrap& obj);
	~ScavTrap();
	ScavTrap&					operator=(const ScavTrap& rhs);
	void						attack(const std::string& target);
	void						guardGate();
	static const unsigned int	scavtrap_init_hit_points = 100;
	static const unsigned int	scavtrap_init_energy_points = 50;
	static const unsigned int	scavtrap_init_attack_damage = 20;
};

#endif

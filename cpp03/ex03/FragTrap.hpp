#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include	"ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
private:
	;
public:
	FragTrap();
	FragTrap(const std::string& name);
	FragTrap(const FragTrap& obj);
	~FragTrap();
	FragTrap&					operator=(const FragTrap& rhs);
	void						attack(const std::string& target);
	void						highFivesGuys(void);
	static const unsigned int	fragtrap_init_hit_points = 100;
	static const unsigned int	fragtrap_init_energy_points = 100;
	static const unsigned int	fragtrap_init_attack_damage = 30;
};

#endif

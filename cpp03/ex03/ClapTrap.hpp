#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include	<string>
# include	<iostream>

class ClapTrap
{
protected:
	std::string		name;
	unsigned int	hit_points;
	unsigned int	energy_points;
	unsigned int	attack_damage;
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(ClapTrap& obj);
	~ClapTrap();
	ClapTrap&					operator=(const ClapTrap& rhs);
	virtual void				attack(const std::string& target);
	void						takeDamage(unsigned int amount);
	void						beRepaired(unsigned int amount);
	static const unsigned int	claptrap_init_hit_points = 10;
	static const unsigned int	claptrap_init_energy_points = 10;
	static const unsigned int	claptrap_init_attack_damage = 0;
};

#endif

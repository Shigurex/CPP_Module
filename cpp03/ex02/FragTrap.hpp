#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include	"ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
	;
public:
	FragTrap();
	FragTrap(const std::string& name);
	FragTrap(FragTrap& obj);
	~FragTrap();
	FragTrap&	operator=(const FragTrap& rhs);
	void		attack(const std::string& target);
	void		highFivesGuys(void);
};

#endif

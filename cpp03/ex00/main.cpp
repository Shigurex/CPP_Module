#include	"ClapTrap.hpp"

int	main(void)
{
	ClapTrap	Bob("Bob");

	Bob.attack("Thomas");
	Bob.attack("Thomas");
	Bob.attack("Thomas");
	Bob.attack("Thomas");
	Bob.attack("Thomas");
	Bob.attack("Thomas");
	Bob.attack("Thomas");
	Bob.attack("Thomas");
	Bob.attack("Thomas");
	Bob.takeDamage(4);
	Bob.beRepaired(10);
	Bob.beRepaired(10);
	Bob.takeDamage(16);
	return (0);
}

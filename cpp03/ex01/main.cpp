#include	"ScavTrap.hpp"

int	main(void)
{
	ScavTrap	Bob("Bob");

	Bob.guardGate();
	Bob.attack("George");
	return (0);
}

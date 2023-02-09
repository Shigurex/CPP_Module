#include	"Zombie.hpp"

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

int	main(void)
{
	Zombie	*new_zombie;

	Zombie	zombie("zombie");
	zombie.announce();
	new_zombie = newZombie("new_zombie");
	new_zombie->announce();
	randomChump("random_zombie");
	delete new_zombie;
	return (0);
}

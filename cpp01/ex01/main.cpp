#include	"Zombie.hpp"

#define SIZE 4

Zombie*	zombieHorde(int N, std::string name);

int	main(void)
{
	Zombie	*zombie_horde = zombieHorde(SIZE, "zombie_horde");

	for (int i = 0; i < SIZE; i++)
		zombie_horde[i].announce();
	delete [] zombie_horde;
	return (0);
}

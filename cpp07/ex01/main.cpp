#include	"iter.hpp"

static void	increment(int& i)
{
	i++;
}

int	main(void)
{
	int	array[] = {1,4,2,4,7,98,2,423,645};

	std::size_t size = sizeof(array) / sizeof(int);
	std::cout << "before iter:" << std::endl;
	for (std::size_t i = 0; i < size; i++)
		std::cout << "[" << i << "]" << array[i] << std::endl;
	iter(array, size, increment);
	std::cout << "after iter:" << std::endl;
	for (std::size_t i = 0; i < size; i++)
		std::cout << "[" << i << "]" << array[i] << std::endl;
}

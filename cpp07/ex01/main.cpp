#include	"iter.hpp"

static void	increment(int& i)
{
	i++;
}

static void	multiplyByFive(int& i)
{
	i *= 5;
}

static void	printArray(int array[], size_t size)
{
	for (std::size_t i = 0; i < size; i++) {
		std::cout << "[" << i << "]" << array[i];
		if (i != size - 1)
			std::cout << ", ";
		else
			std::cout << std::endl;
	}
}

int	main(void)
{
	int	array[] = {1,4,2,4,7,98,2,423,645};

	std::size_t size = sizeof(array) / sizeof(int);
	std::cout << "before iter:" << std::endl;
	printArray(array, size);
	iter(array, size, increment);
	std::cout << "after increment:" << std::endl;
	printArray(array, size);
	iter(array, size, multiplyByFive);
	std::cout << "after multiplied by five:" << std::endl;
	printArray(array, size);
}

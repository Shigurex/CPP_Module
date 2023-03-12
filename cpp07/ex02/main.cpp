#include	"Array.hpp"

int	main(void)
{
	unsigned int	size = 10;
	Array<int>		array(size);

	for (unsigned i = 0; i < size; i++)
		array[i] = i;
	std::cout << "array size: " << array.size() << std::endl;
	try
	{
		for (unsigned i = 0; i <= size; i++)
			std::cout << array[i] << ((i + 1 == size) ? "\n" : " ");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	Array<int>		copy_array(array);
	std::cout << "copy_array size: " << copy_array.size() << std::endl;
	try
	{
		for (unsigned i = 0; i <= size; i++)
			std::cout << copy_array[i] << ((i + 1 == size) ? "\n" : " ");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	Array<int>		copy_assignment_array;
	std::cout << "copy_assignment_array size (before): " << copy_assignment_array.size() << std::endl;
	try
	{
		for (unsigned i = 0; i <= size; i++)
			std::cout << copy_assignment_array[i] << ((i + 1 == size) ? "\n" : " ");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	copy_assignment_array = array;
	std::cout << "copy_assignment_array size (after): " << copy_assignment_array.size() << std::endl;
	try
	{
		for (unsigned i = 0; i <= size; i++)
			std::cout << copy_assignment_array[i] << ((i + 1 == size) ? "\n" : " ");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}

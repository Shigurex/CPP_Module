#include	"easyfind.hpp"
#include	<vector>
#include	<list>
#include	<iostream>

int	main(void)
{
	int							original_data[] = {1, 4, 6, 2, 5, 8, 10};
	std::vector<int>			vector_array(original_data, original_data + sizeof(original_data) / sizeof(int));
	std::vector<int>::iterator	vector_found_iter;

	try
	{
		vector_found_iter = easyfind(vector_array, 8);
		std::cout << "found " << *vector_found_iter << " from the original data" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		vector_found_iter = easyfind(vector_array, 3);
		std::cout << "found " << *vector_found_iter << " from the original data" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	std::list<int>				list_array(original_data, original_data + sizeof(original_data) / sizeof(int));
	std::list<int>::iterator	list_found_iter;
	try
	{
		list_found_iter = easyfind(list_array, 10);
		std::cout << "found " << *list_found_iter << " from the original data" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		list_found_iter = easyfind(list_array, 12);
		std::cout << "found " << *list_found_iter << " from the original data" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}

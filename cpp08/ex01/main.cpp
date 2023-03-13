#include	"Span.hpp"
#include	<iostream>
#include	<cstdlib>

int	main()
{
	Span sp = Span(5);
	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "shortest span (sp): " << sp.shortestSpan() << std::endl;
		std::cout << "shortest span (sp): " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	Span sp_small = Span(1);
	try
	{
		sp_small.addNumber(6);
		sp_small.addNumber(12);
		std::cout << "shortest span (sp_small): " << sp_small.shortestSpan() << std::endl;
		std::cout << "shortest span (sp_small): " << sp_small.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	Span sp_random = Span(10000);
	std::vector<int>	vec_random(10000);
	std::srand(time(NULL));
	try
	{
		std::generate(vec_random.begin(), vec_random.end(), std::rand);
		sp_random.addAtOnce(vec_random);
		std::cout << "shortest span (sp_random): " << sp_random.shortestSpan() << std::endl;
		std::cout << "shortest span (sp_random): " << sp_random.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}

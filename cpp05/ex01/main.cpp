#include	"Bureaucrat.hpp"
#include	"Form.hpp"

int	main(void)
{
	Form	form("form", 100, 60);

	std::cout << form << std::endl;
	try
	{
		Form	form_low("form low", 160, 10);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Form	form_high("form high", 50, -10);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat	bob("bob", 99);
		Bureaucrat	george("george", 101);
		bob.signForm(form);
		george.signForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}

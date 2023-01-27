#include	"PhoneBook.hpp"

int	main(void)
{
	PhoneBook	PhoneBook;
	std::string	command;

	while (true)
	{
		std::getline(std::cin, command);
		if (std::cin.eof() == true)
			;
		if (!command.compare("ADD"))
			;
		else if (!command.compare("SEARCH"))
			;
		else if (!command.compare("EXIT"))
			;
	}
}

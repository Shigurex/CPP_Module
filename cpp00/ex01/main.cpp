#include	"PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phone_book;
	std::string	command;

	while (true)
	{
		std::cout << "Input command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);
		if (std::cin.eof() == true)
			;
		if (!command.compare("ADD"))
			phone_book.InputString();
		else if (!command.compare("SEARCH"))
			;
		else if (!command.compare("EXIT"))
			;
	}
}

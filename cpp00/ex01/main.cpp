#include	"PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phone_book;
	std::string	command;

	while (true)
	{
		std::cout << "Input command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);
		if (std::cin.eof() == true) {
			std::cerr << GETLINE_ERROR_MESSAGE << std::endl;
			exit(EXIT_FAILURE);
		}
		if (!command.compare("ADD"))
			phone_book.Add();
		else if (!command.compare("SEARCH"))
			phone_book.Search();
		else if (!command.compare("EXIT"))
			phone_book.Exit();
	}
}

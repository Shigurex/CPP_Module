#include	"PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->index = 0;
}

PhoneBook::~PhoneBook(void)
{
	;
}

void	PhoneBook::InputString(Contact Contact)
{
	std::cout << "Input first name: ";
	std::getline(std::cin, Contact::FirstName);
	if (std::cin.eof() == true)
		;
	std::cout << "Input last name: ";
	std::getline(std::cin, Contact::LastName);
	if (std::cin.eof() == true)
		;
	this->index++;
}

#include	"PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->index = 0;
	this->is_full = false;
}

PhoneBook::~PhoneBook(void)
{
	;
}

void	PhoneBook::InputString(void)
{
	std::string	first_name;
	std::string	last_name;
	std::string	nick_name;
	std::string	phone_number;
	std::string	darkest_secret;

	std::cout << "Input your first name: ";
	std::getline(std::cin, first_name);
	if (std::cin.eof() == true)
		;
	std::cout << "Input your last name: ";
	std::getline(std::cin, last_name);
	if (std::cin.eof() == true)
		;
	std::cout << "Input your nick name: ";
	std::getline(std::cin, nick_name);
	if (std::cin.eof() == true)
		;
	std::cout << "Input your phone number: ";
	std::getline(std::cin, phone_number);
	if (std::cin.eof() == true)
		;
	std::cout << "Input your darkest secret: ";
	std::getline(std::cin, darkest_secret);
	if (std::cin.eof() == true)
		;
	this->contacts[this->index].SetValue(first_name, last_name, nick_name, phone_number, darkest_secret);
	this->index++;
	if (this->index == 8)
		this->is_full = true;
	this->index %= 8;
}

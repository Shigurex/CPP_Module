#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include	"Contact.hpp"
#include	<iostream>
#include	<iomanip>
#include	<stdlib.h>

# define MAX_CONTACT 8
# define MAX_LEN 10

# define FIRST_NAME_MESSAGE "Input your first name: "
# define LAST_NAME_MESSAGE "Input your last name: "
# define NICK_NAME_MESSAGE "Input your nick name: "
# define PHONE_NUMBER_MESSAGE "Input your phone number: "
# define DARKEST_SECRET_MESSAGE "Input your darkest secret: "

# define EXIT_MESSAGE "Exit process"
# define CIN_ERROR_MESSAGE "Failed in cin"

typedef enum
{
	FIRST_NAME,
	LAST_NAME,
	NICK_NAME,
	PHONE_NUMBER,
	DARKEST_SECRET
}	e_info;

class PhoneBook
{
private:
	int		_index;
	bool	_is_full;
	Contact	_contacts[MAX_CONTACT];

	std::string	InputString(std::string message);
	void		SetString(e_info info, std::string message);
	void		OutputStr(std::string str, std::string delimiter, size_t max_len);
	void		OutputExactInfo(int contact_num);
	void		OutputPreciseInfo(int contact_num);
public:
	PhoneBook();
	~PhoneBook();
	void		Add(void);
	void		Search(void);
	void		Exit(void);
};

#endif

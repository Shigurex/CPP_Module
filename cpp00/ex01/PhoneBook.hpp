#include	"Contact.hpp"
#include	<iostream>

class PhoneBook
{
private:
	int8_t	index;
	bool	is_full;
	Contact	contacts[8];
public:
	PhoneBook();
	~PhoneBook();
	void	PhoneBook::InputString(void);
};

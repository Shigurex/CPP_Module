#include	"Contact.hpp"

Contact::Contact(void)
{
	;
}

Contact::~Contact(void)
{
	;
}



void	Contact::SetValue(std::string FirstName, std::string LastName, std::string Nickname, std::string PhoneNumber, std::string DarkestSecret)
{
	this->FirstName = FirstName;
	this->LastName = LastName;
	this->Nickname = Nickname;
	this->PhoneNumber = PhoneNumber;
	this->DarkestSecret = DarkestSecret;
}

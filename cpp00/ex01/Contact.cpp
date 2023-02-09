#include	"Contact.hpp"

Contact::Contact(void)
{
	;
}

Contact::~Contact(void)
{
	;
}

void	Contact::SetFirstName(std::string first_name)
{
	this->_first_name = first_name;
}

void	Contact::SetLastName(std::string last_name)
{
	this->_last_name = last_name;
}

void	Contact::SetNickName(std::string nick_name)
{
	this->_nick_name = nick_name;
}

void	Contact::SetPhoneNumber(std::string phone_number)
{
	this->_phone_number = phone_number;
}

void	Contact::SetDarkestSecret(std::string darkest_secret)
{
	this->_darkest_secret = darkest_secret;
}

std::string	Contact::GetFirstName(void) const
{
	return (this->_first_name);
}

std::string	Contact::GetLastName(void) const
{
	return (this->_last_name);
}

std::string	Contact::GetNickName(void) const
{
	return (this->_nick_name);
}

std::string	Contact::GetPhoneNumber(void) const
{
	return (this->_phone_number);
}

std::string	Contact::GetDarkestSecret(void) const
{
	return (this->_darkest_secret);
}

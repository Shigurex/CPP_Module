#ifndef CONTACT_HPP
# define CONTACT_HPP

#include	<string>

class Contact {
private:
	std::string	_first_name;
	std::string	_last_name;
	std::string	_nick_name;
	std::string	_phone_number;
	std::string	_darkest_secret;
public:
	Contact();
	~Contact();
	void		SetFirstName(std::string first_name);
	void		SetLastName(std::string last_name);
	void		SetNickName(std::string nick_name);
	void		SetPhoneNumber(std::string phone_number);
	void		SetDarkestSecret(std::string darkest_secret);
	std::string	GetFirstName(void) const;
	std::string	GetLastName(void) const;
	std::string	GetNickName(void) const;
	std::string	GetPhoneNumber(void) const;
	std::string	GetDarkestSecret(void) const;
};

#endif

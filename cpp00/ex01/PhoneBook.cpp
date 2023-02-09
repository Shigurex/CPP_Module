#include	"PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_index = 0;
	this->_is_full = false;
}

PhoneBook::~PhoneBook(void)
{
	;
}

std::string	PhoneBook::InputString(std::string message)
{
	std::string	str;

	while (true) {
		std::cout << message;
		std::getline(std::cin, str);
		if (std::cin.eof() == true) {
			std::cerr << GETLINE_ERROR_MESSAGE << std::endl;
			exit(EXIT_FAILURE);
		}
		else if (str.empty())
			continue ;
		break ;
	}
	return (str);
}

void	PhoneBook::SetString(e_info info, std::string message)
{
	std::string	str;

	str = InputString(message);
	if (info == FIRST_NAME)
		this->_contacts[this->_index].SetFirstName(str);
	else if (info == LAST_NAME)
		this->_contacts[this->_index].SetLastName(str);
	else if (info == NICK_NAME)
		this->_contacts[this->_index].SetNickName(str);
	else if (info == PHONE_NUMBER)
		this->_contacts[this->_index].SetPhoneNumber(str);
	else if (info == DARKEST_SECRET)
		this->_contacts[this->_index].SetDarkestSecret(str);
}

void	PhoneBook::OutputStr(std::string str, std::string delimiter, size_t max_len)
{
	if (max_len < 1)
		return ;
	else if (str.length() > max_len)
		std::cout << str.substr(0, max_len - 1) << "." << delimiter;
	else
		std::cout << std::setw(max_len) << str << delimiter;
}

void	PhoneBook::OutputExactInfo(int contact_num)
{
	int	i;

	for (i = 0; i < contact_num; i++) {
		OutputStr(std::to_string(i + 1), "|", MAX_LEN);
		OutputStr(this->_contacts[i].GetFirstName(), "|", MAX_LEN);
		OutputStr(this->_contacts[i].GetLastName(), "|", MAX_LEN);
		OutputStr(this->_contacts[i].GetNickName(), "\n", MAX_LEN);
	}
}

void	PhoneBook::OutputPreciseInfo(int contact_num)
{
	std::string	str;
	const char	*tmp;
	int			index;

	str = InputString(INDEX_MESSAGE);
	tmp = str.c_str();
	index = std::atoi(tmp);
	if (index <= 0 || contact_num < index) {
		std::cerr << INDEX_ERROR_MESSAGE << std::endl;
		return ;
	}
	std::cout << "First name: " << this->_contacts[index - 1].GetFirstName() << std::endl;
	std::cout << "Last name: " << this->_contacts[index - 1].GetLastName() << std::endl;
	std::cout << "Nick name: " << this->_contacts[index - 1].GetNickName() << std::endl;
	std::cout << "Phone number: " << this->_contacts[index - 1].GetPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << this->_contacts[index - 1].GetDarkestSecret() << std::endl;
}

void	PhoneBook::Add(void)
{
	SetString(FIRST_NAME, FIRST_NAME_MESSAGE);
	SetString(LAST_NAME, LAST_NAME_MESSAGE);
	SetString(NICK_NAME, NICK_NAME_MESSAGE);
	SetString(PHONE_NUMBER, PHONE_NUMBER_MESSAGE);
	SetString(DARKEST_SECRET, DARKEST_SECRET_MESSAGE);
	this->_index++;
	if (this->_index == MAX_CONTACT) {
		this->_is_full = true;
		this->_index = 0;
	}
}

void	PhoneBook::Search(void)
{
	int	contact_num;

	if (this->_is_full)
		contact_num = MAX_CONTACT;
	else
		contact_num = this->_index;
	OutputExactInfo(contact_num);
	OutputPreciseInfo(contact_num);
}

void	PhoneBook::Exit(void)
{
	std::cout << EXIT_MESSAGE << std::endl;
	exit(EXIT_SUCCESS);
}

#include	"BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : file_name(EMPTY_STRING)
{
	;
}

BitcoinExchange::BitcoinExchange(std::string file_name) : file_name(file_name)
{
	;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj)
{
	*this = obj;
}

BitcoinExchange::~BitcoinExchange()
{
	;
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& rhs)
{
	this->file_name = rhs.file_name;
	return (*this);
}

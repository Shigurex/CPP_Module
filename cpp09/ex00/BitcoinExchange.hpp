#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include	<iostream>

# define EMPTY_STRING ""

class BitcoinExchange
{
private:
	std::string	file_name;
public:
	BitcoinExchange();
	BitcoinExchange(std::string file_name);
	BitcoinExchange(const BitcoinExchange& obj);
	~BitcoinExchange();
	BitcoinExchange&	operator=(const BitcoinExchange& rhs);
};

#endif

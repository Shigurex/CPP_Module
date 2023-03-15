#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include	<iostream>
# include	<fstream>
# include	<cstdlib>
# include	<map>

# define EMPTY_STRING ""
# define SPACES "\t\n\v\f\r "
# define DATA_CSV "data.csv"

class BitcoinExchange
{
private:
	std::string						file_name;
	std::map<std::string, float>	data;

	void		trimSpaces(std::string& str);
	void		checkValidDateFormat(std::string& date);
	float		convertStrToFloat(std::string value);
	std::string	getPreviousDay(std::string& date);
	std::string	getStrDate(int year, int month, int day);
	int			getMaxDayPerMonth(int year, int month);
public:
	BitcoinExchange();
	BitcoinExchange(std::string file_name);
	BitcoinExchange(const BitcoinExchange& obj);
	~BitcoinExchange();
	BitcoinExchange&			operator=(const BitcoinExchange& rhs);
	void						inputDataCsv(void);
	void						checkTextFile(void);

	static const std::string	data_csv_name;

	class FileErrorException : public std::exception
	{
		virtual const char	*what() const throw();
	};

	class LargeNumberException : public std::exception
	{
		virtual const char	*what() const throw();
	};

	class BadInputException : public std::exception
	{
		virtual const char	*what() const throw();
	};

	class NotPositiveNumberException : public std::exception
	{
		virtual const char	*what() const throw();
	};

	class FoundNoDataException : public std::exception
	{
		virtual const char	*what() const throw();
	};
};

#endif

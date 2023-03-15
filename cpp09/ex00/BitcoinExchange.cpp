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
	this->data = rhs.data;
	return (*this);
}

void	BitcoinExchange::trimSpaces(std::string& str)
{
	size_t	start, end;

	start = str.find_first_not_of(SPACES);
	if (start == std::string::npos)
		throw BadInputException();
	end = str.find_last_not_of(SPACES);
	str = str.substr(start, end - start + 1);
}

int	BitcoinExchange::getMaxDayPerMonth(int year, int month)
{
	int	day;

	switch (month)
	{
		case 2:
			if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
				day = 29;
			else
				day = 28;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			day = 30;
			break ;
		default:
			day = 31;
			break;
	}
	return (day);
}

void	BitcoinExchange::checkValidDateFormat(std::string& date)
{
	size_t	size = date.length();
	int		year;
	int		month;
	int		day;

	if (size != 10)
		throw BadInputException();
	for (size_t i = 0; i < size; i++) {
		if (i == 4 || i == 7) {
			if (date[i] != '-')
				throw BadInputException();
		} else {
			if (!std::isdigit(date[i]))
				throw BadInputException();
		}
	}
	year = std::atoi(date.substr(0, 4).c_str());
	month = std::atoi(date.substr(5, 2).c_str());
	day = std::atoi(date.substr(8, 2).c_str());
	if (month < 1 || 12 < month)
		throw BadInputException();
	if (day < 1 || getMaxDayPerMonth(year, month) < day)
		throw BadInputException();
}

std::string	BitcoinExchange::getStrDate(int year, int month, int day)
{
	std::string year_str = std::string(4 - std::to_string(year).length(), '0').append(std::to_string(year));
	std::string month_str = std::string(2 - std::to_string(month).length(), '0').append(std::to_string(month));
	std::string day_str = std::string(2 - std::to_string(day).length(), '0').append(std::to_string(day));

	return (year_str + "-" + month_str + "-" + day_str);
}

std::string	BitcoinExchange::getPreviousDay(std::string& date)
{
	int	year = std::atoi(date.substr(0, 4).c_str());
	int	month = std::atoi(date.substr(5, 2).c_str());
	int	day = std::atoi(date.substr(8, 2).c_str());

	day--;
	if (day <= 0) {
		month--;
		if (month <= 0) {
			if (year <= 0)
				throw FoundNoDataException();
			year--;
			month = 12;
		}
		day = getMaxDayPerMonth(year, month);
	}
	return (getStrDate(year, month, day));
}

float	BitcoinExchange::convertStrToFloat(std::string value)
{
	float	float_value;
	char	*remain = NULL;

	float_value = strtof(value.c_str(), &remain);
	if (!remain || remain[0])
		throw BadInputException();
	return (float_value);
}

void	BitcoinExchange::inputDataCsv(void)
{
	std::ifstream	ifs;
	std::string		line;
	size_t			comma_pos;
	std::string		date;
	std::string		exchange_rate_str;
	float			exchange_rate;

	ifs.open(data_csv_name);
	if (ifs.fail())
		throw FileErrorException();
	while (std::getline(ifs, line)) {
		if (line.compare(EMPTY_STRING) == 0)
			continue ;
		comma_pos = line.find(',');
		if (comma_pos == std::string::npos)
			throw BadInputException();
		date = line.substr(0, comma_pos);
		trimSpaces(date);
		exchange_rate_str = line.substr(comma_pos + 1, line.length() - comma_pos - 1);
		trimSpaces(exchange_rate_str);
		if (date.compare("date") == 0 && exchange_rate_str.compare("exchange_rate") == 0)
			continue ;
		checkValidDateFormat(date);
		exchange_rate = convertStrToFloat(exchange_rate_str);
		this->data[date] = exchange_rate;
	}
	ifs.close();
}

void	BitcoinExchange::checkTextFile(void)
{
	std::ifstream	ifs;
	std::string		line;
	size_t			pipe_pos;
	std::string		date;
	std::string		value_str;
	float			value;

	ifs.open(this->file_name);
	if (ifs.fail())
		throw FileErrorException();
	while (std::getline(ifs, line)) {
		try
		{
			if (line.compare(EMPTY_STRING) == 0)
				continue ;
			pipe_pos = line.find('|');
			if (pipe_pos == std::string::npos)
				throw BadInputException();
			date = line.substr(0, pipe_pos);
			trimSpaces(date);
			value_str = line.substr(pipe_pos + 1, line.length() - pipe_pos - 1);
			trimSpaces(value_str);
			if (date.compare("date") == 0 && value_str.compare("value") == 0)
				continue ;
			checkValidDateFormat(date);
			value = convertStrToFloat(value_str);
			if (value < 0)
				throw NotPositiveNumberException();
			else if (1000 < value)
				throw LargeNumberException();
			std::string	last_date = date;
			while (this->data.find(last_date) == this->data.end())
				last_date = getPreviousDay(last_date);
			std::cout << date << " => " << value << " = " << this->data[last_date] * value << std::endl;
		}
		catch(const BadInputException& e)
		{
			std::cerr << "Error: bad input" << " => " << line << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}

const std::string	BitcoinExchange::data_csv_name = "data.csv";

const char	*BitcoinExchange::FileErrorException::what() const throw()
{
	return ("Error: could not open file.");
}

const char	*BitcoinExchange::LargeNumberException::what() const throw()
{
	return ("Error: too large a number.");
}

const char	*BitcoinExchange::BadInputException::what() const throw()
{
	return ("Error: bad input");
}

const char	*BitcoinExchange::NotPositiveNumberException::what() const throw()
{
	return ("Error: not a positive number.");
}

const char	*BitcoinExchange::FoundNoDataException::what() const throw()
{
	return ("Error: found no data for the date.");
}

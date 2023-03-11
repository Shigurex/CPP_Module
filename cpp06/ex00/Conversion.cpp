#include	"Conversion.hpp"

Conversion::Conversion() : _input(""), _type(NONE), _input_char(0), _input_int(0), _input_float(0), _input_double(0)
{
	;
}

Conversion::Conversion(std::string input) : _input(input), _type(NONE), _input_char(0), _input_int(0), _input_float(0), _input_double(0)
{
	;
}

Conversion::~Conversion()
{
	;
}

Conversion::Conversion(const Conversion& obj)
{
	*this = obj;
}

Conversion&	Conversion::operator=(const Conversion& rhs)
{
	this->_input = rhs._input;
	this->_type = rhs._type;
	this->_input_char = rhs._input_char;
	this->_input_int = rhs._input_int;
	this->_input_float = rhs._input_float;
	this->_input_double = rhs._input_double;
	return (*this);
}

void	Conversion::parse(void)
{
	char	*endptr = NULL;
	double	output;
	bool	is_float = false;
	size_t	input_length = this->_input.length();
	size_t	f_pos = this->_input.find_last_of('f');

	if (input_length == 0)
		return ;
	else if (input_length == 1 && !std::isdigit(this->_input[0])) {
		this->_type = CHAR;
		this->_input_char = this->_input[0];
	}
	else {
		if (!this->_input.compare("+nan") || !this->_input.compare("-nan"))
			return ;
		if (!(!this->_input.compare("inf") || !this->_input.compare("+inf") || !this->_input.compare("-inf")) 
			&& f_pos != std::string::npos && f_pos + 1 == input_length) {
			this->_input = this->_input.substr(0, f_pos);
			is_float = true;
		}
		output = std::strtod(this->_input.c_str(), &endptr);
		if (!endptr || endptr[0])
			return ;
		if (is_float || !this->_input.compare("nan")) {
			this->_type = FLOAT;
			this->_input_float = std::strtof(this->_input.c_str(), NULL);
		} else if (this->_input.find(".") == std::string::npos && (std::numeric_limits<int>::min() <= output && output <= std::numeric_limits<int>::max())) {
			this->_type = INT;
			this->_input_int = std::atoi(this->_input.c_str());
		} else {
			this->_type = DOUBLE;
			this->_input_double = std::strtod(this->_input.c_str(), NULL);
		}
	}
}

template <class T>
std::string	Conversion::_putZero(T value)
{
	if (value - static_cast<int>(value) == 0)
		return (".0");
	return ("");
}

template <class T>
void	Conversion::_printConvertChar(T value)
{
	if (value < std::numeric_limits<char>::min() || std::numeric_limits<char>::max() < value)
		std::cout << "char: impossible" << std::endl;
	else if (value < 32 || 126 < value)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
}

template <class T>
void	Conversion::_printConvertInt(T value)
{
	if (value < std::numeric_limits<int>::min() || std::numeric_limits<int>::max() < value)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
}

template <class T>
void	Conversion::_printConvertFloat(T value)
{
	if (value < -std::numeric_limits<float>::max())
		std::cout << "float: -inff" << std::endl;
	else if (value > std::numeric_limits<float>::max())
		std::cout << "float: +inff" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(value) << _putZero(static_cast<float>(value)) << "f" << std::endl;
}

template <class T>
void	Conversion::_printConvertDouble(T value)
{
	if (value < -std::numeric_limits<double>::max())
		std::cout << "double: -inf" << std::endl;
	else if (value > std::numeric_limits<double>::max())
		std::cout << "double: +inf" << std::endl;
	else
		std::cout << "double: " << static_cast<double>(value) << _putZero(static_cast<double>(value)) << std::endl;
}

void	Conversion::_printChar(void)
{
	if (this->_type == CHAR)
		_printConvertChar<char>(this->_input_char);
	else if (this->_type == INT)
		_printConvertChar<int>(this->_input_int);
	else if (this->_type == FLOAT) {
		if (!this->_input.compare("nan") || !this->_input.compare("inf"))
			std::cout << "char: impossible" << std::endl;
		else
			_printConvertChar<float>(this->_input_float);
	} else if (this->_type == DOUBLE) {
		if (!this->_input.compare("nan") || !this->_input.compare("inf"))
			std::cout << "char: impossible" << std::endl;
		else
			_printConvertChar<double>(this->_input_double);
	}
}

void	Conversion::_printInt(void)
{
	if (this->_type == CHAR)
		_printConvertInt<char>(this->_input_char);
	else if (this->_type == INT)
		_printConvertInt<int>(this->_input_int);
	else if (this->_type == FLOAT) {
		if (!this->_input.compare("nan") || !this->_input.compare("inf"))
			std::cout << "int: impossible" << std::endl;
		else
			_printConvertInt<float>(this->_input_float);
	} else if (this->_type == DOUBLE) {
		if (!this->_input.compare("nan") || !this->_input.compare("inf"))
			std::cout << "int: impossible" << std::endl;
		else
			_printConvertInt<double>(this->_input_double);
	}
}

void	Conversion::_printFloat(void)
{
	if (this->_type == CHAR)
		_printConvertFloat<char>(this->_input_char);
	else if (this->_type == INT)
		_printConvertFloat<int>(this->_input_int);
	else if (this->_type == FLOAT)
		_printConvertFloat<float>(this->_input_float);
	else if (this->_type == DOUBLE)
		_printConvertFloat<double>(this->_input_double);
}

void	Conversion::_printDouble(void)
{
	if (this->_type == CHAR)
		_printConvertDouble<char>(this->_input_char);
	else if (this->_type == INT)
		_printConvertDouble<int>(this->_input_int);
	else if (this->_type == FLOAT)
		_printConvertDouble<float>(this->_input_float);
	else if (this->_type == DOUBLE)
		_printConvertDouble<double>(this->_input_double);
}

void	Conversion::printConversion(void)
{
	if (this->_type == NONE)
		std::cerr << "invalid input" << std::endl;
	_printChar();
	_printInt();
	_printFloat();
	_printDouble();
}

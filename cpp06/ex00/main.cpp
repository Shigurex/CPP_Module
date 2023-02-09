# include	<cctype>
# include	<iostream>
# include	<iomanip>
# include	<ctype.h>
# include	<string>
# include	<limits>
# include	<math.h>
# include	<cmath>

# define CHAR "char: "
# define INT "int: "
# define FLOAT "float: "
# define DOUBLE "double: "

# define CHAR_NUM 1
# define INT_NUM 2
# define FLOAT_NUM 3
# define DOUBLE_NUM 4

// void	parse_type(std::string str)
// {
	
// }

template <class Type>
void	ConvertTypeToChar(Type value)
{
	if (value < std::numeric_limits<char>::min() || std::numeric_limits<char>::max() < value)
		std::cout << CHAR << "impossible" << std::endl;
	else if (value < 32 || 126 < value)
		std::cout << CHAR << "Non displayable" << std::endl;
	else
		std::cout << CHAR << "'" << static_cast<char>(value) << "'" << std::endl;
}

template <class Type>
void	ConvertTypeToInt(Type value)
{
	if (value < std::numeric_limits<int>::min() || std::numeric_limits<int>::max() < value)
		std::cout << INT << "impossible" << std::endl;
	else
		std::cout << INT << static_cast<int>(value) << std::endl;
}

template <class Type>
void	ConvertTypeToFloat(Type value)
{
	if (value < std::numeric_limits<float>::min())
		std::cout << FLOAT << "-inff" << std::endl;
	else if (value > std::numeric_limits<float>::max())
		std::cout << FLOAT << "inff" << std::endl;
	else
		std::cout << FLOAT << static_cast<float>(value) << "f" << std::endl;
}

template <class Type>
void	ConvertTypeToDouble(Type value)
{
	if (value < std::numeric_limits<double>::min())
		std::cout << DOUBLE << "-inf" << std::endl;
	else if (value > std::numeric_limits<double>::max())
		std::cout << DOUBLE << "inf" << std::endl;
	else
		std::cout << DOUBLE << static_cast<double>(value) << std::endl;
}

void	ConvertChar(char c)
{
	ConvertTypeToChar<char>(c);
	ConvertTypeToInt<char>(c);
	ConvertTypeToFloat<char>(c);
	ConvertTypeToDouble<char>(c);
}

void	ConvertInt(int n)
{
	ConvertTypeToChar<int>(n);
	ConvertTypeToInt<int>(n);
	ConvertTypeToFloat<int>(n);
	ConvertTypeToDouble<int>(n);
}

void	ConvertFloat(float f)
{
	if (std::isnan(f) || std::isinf(f))
		std::cout << CHAR << "impossible" << std::endl;
	else
		ConvertTypeToChar<float>(f);
	if (std::isnan(f) || std::isinf(f))
		std::cout << INT << "impossible" << std::endl;
	else
		ConvertTypeToInt<float>(f);
	ConvertTypeToFloat<float>(f);
	ConvertTypeToDouble<float>(f);
}

void	ConvertDouble(double d)
{
	if (std::isnan(d) || std::isinf(d))
		std::cout << CHAR << "impossible" << std::endl;
	else
		ConvertTypeToChar<double>(d);
	if (std::isnan(d) || std::isinf(d))
		std::cout << INT << "impossible" << std::endl;
	else
		ConvertTypeToInt<double>(d);
	ConvertTypeToFloat<double>(d);
	ConvertTypeToDouble<double>(d);
}

void	parse(std::string str)
{
	if (str.find(".") != std::string::npos && str.find("f") != std::string::npos)
		ConvertFloat(std::stof(str));
	else if (str.find(".") == std::string::npos && std::numeric_limits<int>::min() <= std::stod(str) && std::stod(str) <= std::numeric_limits<int>::max())
		ConvertInt(std::stoi(str));
	else if (str.length() == 1)
		ConvertChar('a');
	else
		ConvertDouble(std::stod(str));
}

int	main(int argc, char **argv)
{
	std::string	str;

	if (argc != 2) {
		std::cerr << "Invalid argument" << std::endl;
		exit(EXIT_FAILURE);
	}
	str = std::string(argv[1]);
	parse(str);
	return (0);
}

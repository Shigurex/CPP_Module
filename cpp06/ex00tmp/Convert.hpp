#ifndef CONVERT_HPP
# define CONVERT_HPP

# include	<cctype>
# include	<iostream>
# include	<ctype.h>
# include	<string>

# define CHAR "char: "
# define INT "int: "
# define FLOAT "float: "
# define DOUBLE "double: "

class Convert
{
private:
	std::string	_str;
public:
	Convert(std::string str);
	~Convert();
	template <class Type>
	static void	PrintTypeAndValue(std::string type, Type value);
	static void	ConvertIntToChar(int n);
	static void	ConvertType(std::string str);
};

#endif

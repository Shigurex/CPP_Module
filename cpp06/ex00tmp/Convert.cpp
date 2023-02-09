#include	"Convert.hpp"

Convert::Convert(std::string str): _str(str)
{
}

template <class Type>
void	Convert::PrintTypeAndValue(std::string type, Type value)
{
	if (!type.compare(FLOAT))
		std::cout << type << value << "f" << std::endl;
	else
		std::cout << type << value << std::endl;
}

void	Convert::ConvertIntToChar(int n)
{
	if (!isascii(n))
		PrintTypeAndValue<std::string>(CHAR, "impossible");
	else if (!std::isprint(n))
		PrintTypeAndValue<std::string>(CHAR, "Non displayable");
	else
		PrintTypeAndValue<char>(CHAR, static_cast<char>(n));
}

void	Convert::ConvertType(std::string str)
{
	ConvertIntToChar(10);
	ConvertIntToChar(100);
	ConvertIntToChar(1000);
}

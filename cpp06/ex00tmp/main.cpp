#include	"Convert.hpp"

int	main(int argc, char **argv)
{
	std::string	str;

	if (argc != 2) {
		std::cerr << "Invalid argument" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	std::cout << std::nan << std::endl;
	str = std::string(argv[1]);
	Convert::ConvertType(str);
	return (0);
}

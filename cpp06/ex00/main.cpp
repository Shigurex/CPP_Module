#include	"Conversion.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "invalid number of arguments" << std::endl;
		return (1);
	}
	std::string	input(argv[1]);
	Conversion	conversion(input);
	conversion.parse();
	conversion.printConversion();
	return (0);
}

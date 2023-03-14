#include	"RPN.hpp"

// code to get INT_MAX
// ./RPN "01-22*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*+22*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*+"
// code to get INT_MIN
// ./RPN "022*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*-22*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*-"

int	main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Error" << std::endl;
		return (1);
	}
	try
	{
		std::string	raw_string(argv[1]);
		RPN	rpn(raw_string);
		rpn.parse();
		std::cout << rpn.calculate() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}

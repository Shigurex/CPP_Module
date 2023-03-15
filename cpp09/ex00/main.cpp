#include	"BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Error: could not open file." << std::endl;
		exit(EXIT_FAILURE);
	}
	try
	{
		BitcoinExchange	bitcoin(argv[1]);
		bitcoin.inputDataCsv();
		bitcoin.checkTextFile();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}

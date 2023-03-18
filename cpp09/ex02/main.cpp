#include	"PmergeMe.hpp"

static int	strToInt(char *str)
{
	long	value;
	char	*remain = NULL;

	value = std::strtol(str, &remain, 10);
	if (!remain || remain[0]) {
		std::cerr << "invalid argument" << std::endl;
		exit(EXIT_FAILURE);
	}
	if (value < std::numeric_limits<int>::min() || std::numeric_limits<int>::max() < value) {
		std::cerr << "value overflow" << std::endl;
		exit(EXIT_FAILURE);
	}
	return (static_cast<int>(value));
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	std::vector<int>	vector;
	std::list<int>		list;

	for (int i = 1; i < argc; i++) {
		vector.push_back(strToInt(argv[i]));
		list.push_back(strToInt(argv[i]));
	}
	PmergeMe	pmerge_me(vector, list);
	pmerge_me.sort();
	return (0);
}

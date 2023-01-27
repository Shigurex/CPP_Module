#include	<iostream>
#include	<string>

int	main(int argc, char *argv[])
{
	std::string	s;

	if (argc == 1)
		s += "* loud and unbearable feedback noise *";
	else
	{
		for (int i = 1; argv[i]; i++)
			s += std::string(argv[i]);
	}
	transform (s.begin(), s.end(), s.begin(), toupper);
	std::cout << s << std::endl;
	return 0;
}

#include	<string>
#include	<iostream>
#include	<iomanip>
#include	<fstream>

#define BUFFER_SIZE 10

std::string	ReadFile(std::string file_name)
{
	if (file_name.empty()) {
		std::cerr << "empty input" << std::endl;
		exit (EXIT_FAILURE);
	}
	std::ifstream	ifs(file_name);
	if (ifs.fail()) {
		std::cerr << "failed to open file" << std::endl;
		exit (EXIT_FAILURE);
	}
	std::string	str((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
	//std::istreambuf_iterator<char>()によりストリームの末尾でさらに文字を読み込まないようにする
	ifs.close();
	return (str);
}

void	ReplaceStr(std::string& str, std::string s1, std::string s2)
{
	std::size_t	current_pos = 0;
	while (true)
	{
		std::size_t	find_pos = str.find(s1, current_pos);
		if (find_pos == std::string::npos)
			break ;
		str.erase(find_pos, s1.length());
		str.insert(find_pos, s2);
		current_pos = find_pos + s2.length();
	}
}

void	OutputStr(std::string file_name, std::string str)
{
	std::ofstream	ofs(file_name + "_replaced");

	if (ofs.fail()) {
		std::cerr << "failed to open file" << std::endl;
		exit (EXIT_FAILURE);
	}
	ofs << str;
	ofs.close();
}

int	main(int argc, char **argv)
{
	if (argc != 4) {
		std::cerr << "Invalid input" << std::endl;
		return (1);
	}
	std::string	file_name(argv[1]);
	std::string	s1(argv[2]);
	std::string	s2(argv[3]);
	if (file_name.empty() || s1.empty() || s2.empty()) {
		std::cerr << "empty input" << std::endl;
		exit (EXIT_FAILURE);
	}
	std::string	str = ReadFile(file_name);
	ReplaceStr(str, s1, s2);
	OutputStr(file_name, str);
	return (0);
}

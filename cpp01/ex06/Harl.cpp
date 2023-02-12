#include	"Harl.hpp"

Harl::Harl()
{
	;
}

Harl::~Harl()
{
	;
}

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << DEBUG_MESSAGE << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << INFO_MESSAGE << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << WARNING_MESSAGE << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << ERROR_MESSAGE << std::endl;
}

void	Harl::complain(std::string level)
{
	std::size_t	i;

	std::string	harl_levels[LEVELS] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (i = 0; i < LEVELS && level.compare(harl_levels[i]); i++);
	switch (i)
	{
	case 0:
		debug();
	case 1:
		info();
	case 2:
		warning();
	case 3:
		error();
		break;
	default:
		std::cout << INVALID_MESSAGE << std::endl;
		break ;
	}
}

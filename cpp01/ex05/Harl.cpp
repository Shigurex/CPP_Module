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
	std::cout << DEBUG_MESSAGE << std::endl;
}

void	Harl::info(void)
{
	std::cout << INFO_MESSAGE << std::endl;
}

void	Harl::warning(void)
{
	std::cout << WARNING_MESSAGE << std::endl;
}

void	Harl::error(void)
{
	std::cout << ERROR_MESSAGE << std::endl;
}

void	Harl::complain(std::string level)
{
	std::size_t	i;

	void (Harl::*f[LEVELS])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	harl_levels[LEVELS] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (i = 0; i < LEVELS && level.compare(harl_levels[i]); i++);
	switch (i)
	{
	case 4:
		std::cerr << "invalid level" << std::endl;
		break;
	default:
		(this->*f[i])();
		break;
	}
}



# include	<iostream>
# include	<string>

# define LEVELS 4

# define DEBUG_MESSAGE "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
# define INFO_MESSAGE "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!"
# define WARNING_MESSAGE "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month."
# define ERROR_MESSAGE "This is unacceptable! I want to speak to the manager now."

class Harl
{
private:
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
public:
	Harl();
	~Harl();
	void	complain(std::string level);
};

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

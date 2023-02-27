#ifndef HARL_HPP
# define HARL_HPP

# include	<iostream>
# include	<string>

# define LEVELS 4

# define DEBUG_MESSAGE "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n"
# define INFO_MESSAGE "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n"
# define WARNING_MESSAGE "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.\n"
# define ERROR_MESSAGE "This is unacceptable! I want to speak to the manager now.\n"
# define INVALID_MESSAGE "[ Probably complaining about insignificant problems ]"

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

#endif

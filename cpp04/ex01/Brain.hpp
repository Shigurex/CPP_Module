#ifndef BRAIN_HPP
# define BRAIN_HPP

# include	<string>
# include	<iostream>
# include	<cstdlib>

# define SIZE 100

class Brain
{
private:
	std::string	ideas[SIZE];
	int			index;
	bool		is_full;
public:
	Brain();
	Brain(const Brain& obj);
	~Brain();
	Brain&		operator=(const Brain& rhs);
	std::string	get_idea(const int index) const;
	void		set_idea(std::string idea);
};

#endif

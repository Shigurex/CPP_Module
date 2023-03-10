#ifndef INTERN_HPP
# define INTERN_HPP

# include	<iostream>
# include	"ShrubberyCreationForm.hpp"
# include	"RobotomyRequestForm.hpp"
# include	"PresidentialPardonForm.hpp"

# define FORM_SIZE 3

class Intern
{
public:
	Intern();
	Intern(const Intern& obj);
	~Intern();
	Intern&	operator=(const Intern& rhs);
	AForm	*makeForm(const std::string name, const std::string target);
};

#endif

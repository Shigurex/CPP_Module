#include	"Intern.hpp"

Intern::Intern()
{
	;
}

Intern::Intern(const Intern& obj)
{
	*this = obj;
}

Intern::~Intern()
{
	;
}

Intern&	Intern::operator=(const Intern& rhs)
{
	(void)rhs;
	return (*this);
}

AForm	*Intern::makeForm(const std::string name, const std::string target)
{
	size_t		index;
	AForm		*form = NULL;
	std::string	form_names[FORM_SIZE] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	for (index = 0; index < FORM_SIZE && name.compare(form_names[index]); index++);
	switch (index)
	{
		case 0:
			form = new ShrubberyCreationForm(target);
			break ;
		case 1:
			form = new RobotomyRequestForm(target);
			break ;
		case 2:
			form = new PresidentialPardonForm(target);
			break ;
		default:
			std::cerr << "invalid name passed as a parameter" << std::endl;
			return (NULL);
	}
	std::cout << "Intern creates " << form->getName() << std::endl;
	return (form);
}

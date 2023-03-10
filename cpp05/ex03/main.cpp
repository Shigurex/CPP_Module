#include	"Bureaucrat.hpp"
#include	"ShrubberyCreationForm.hpp"
#include	"RobotomyRequestForm.hpp"
#include	"PresidentialPardonForm.hpp"
#include	"Intern.hpp"

int	main(void)
{
	Intern	intern;
	AForm	*Form_ShrubberyCreation = intern.makeForm("shrubbery creation", "home");
	AForm	*Form_RobotomyRequest = intern.makeForm("robotomy request", "school");
	AForm	*Form_PresidentialPardon = intern.makeForm("presidential pardon", "office");
	AForm	*Form_Invalid = intern.makeForm("invalid", "office");
	(void)Form_Invalid;

	Bureaucrat	bob("bob", 10);
	bob.signForm(*Form_ShrubberyCreation);
	bob.executeForm(*Form_ShrubberyCreation);

	bob.signForm(*Form_RobotomyRequest);
	bob.executeForm(*Form_RobotomyRequest);

	bob.signForm(*Form_PresidentialPardon);
	bob.executeForm(*Form_PresidentialPardon);

	delete Form_ShrubberyCreation;
	delete Form_RobotomyRequest;
	delete Form_PresidentialPardon;
	return (0);
}

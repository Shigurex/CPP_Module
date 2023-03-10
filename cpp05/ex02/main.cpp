#include	"Bureaucrat.hpp"
#include	"ShrubberyCreationForm.hpp"
#include	"RobotomyRequestForm.hpp"
#include	"PresidentialPardonForm.hpp"

int	main(void)
{
	AForm	*Form_ShrubberyCreation = new ShrubberyCreationForm("home");
	AForm	*Form_RobotomyRequest = new RobotomyRequestForm("school");
	AForm	*Form_PresidentialPardon = new PresidentialPardonForm("office");

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

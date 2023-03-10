#include	"RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("robotomy request", RobotomyRequestForm::grade_to_sign, RobotomyRequestForm::grade_to_execute), target("no_target")
{
	;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("robotomy request", RobotomyRequestForm::grade_to_sign, RobotomyRequestForm::grade_to_execute), target(target)
{
	std::srand(std::time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj)
{
	std::srand(std::time(NULL));
	*this = obj;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
	this->AForm::operator=(rhs);
	const_cast<std::string&>(this->target) = rhs.target;
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > RobotomyRequestForm::grade_to_execute)
		throw AForm::GradeTooLowException();
	if (std::rand() % 2 == 0)
		std::cout << this->target << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->target << " failed to be robotomized" << std::endl;
}

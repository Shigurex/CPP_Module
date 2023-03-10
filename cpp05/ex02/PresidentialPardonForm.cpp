#include	"PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("presidential pardon", PresidentialPardonForm::grade_to_sign, PresidentialPardonForm::grade_to_execute), target("no_target")
{
	;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("presidential pardon", PresidentialPardonForm::grade_to_sign, PresidentialPardonForm::grade_to_execute), target(target)
{
	;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj)
{
	*this = obj;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
	this->AForm::operator=(rhs);
	const_cast<std::string&>(this->target) = rhs.target;
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > PresidentialPardonForm::grade_to_execute)
		throw AForm::GradeTooLowException();
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

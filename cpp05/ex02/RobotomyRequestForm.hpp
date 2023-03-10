#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include	<cstdlib>
# include	"AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	const std::string	target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& obj);
	virtual ~RobotomyRequestForm();
	RobotomyRequestForm&	operator=(const RobotomyRequestForm& rhs);
	void					execute(Bureaucrat const & executor) const;

	static const int		grade_to_sign = 72;
	static const int		grade_to_execute = 45;
};

#endif

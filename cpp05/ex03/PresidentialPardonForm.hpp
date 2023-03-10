#ifndef PRESIDENTIALCREATIONFORM_HPP
# define PRESIDENTIALCREATIONFORM_HPP

# include	"AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	const std::string	target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& obj);
	virtual ~PresidentialPardonForm();
	PresidentialPardonForm&	operator=(const PresidentialPardonForm& rhs);
	void					execute(Bureaucrat const & executor) const;

	static const int		grade_to_sign = 25;
	static const int		grade_to_execute = 5;
};

#endif

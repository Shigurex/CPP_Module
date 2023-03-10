#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include	"AForm.hpp"
# include	<fstream>

class ShrubberyCreationForm : public AForm
{
private:
	const std::string	target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& obj);
	virtual ~ShrubberyCreationForm();
	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& rhs);
	void					execute(Bureaucrat const & executor) const;

	static const int		grade_to_sign = 145;
	static const int		grade_to_execute = 137;
};

#endif

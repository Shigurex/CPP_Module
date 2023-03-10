#ifndef AForm_HPP
# define AForm_HPP

# include	<iostream>
# include	"Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string	name;
	bool				is_signed;
	const int			grade_to_sign;
	const int			grade_to_execute;
public:
	AForm();
	AForm(const std::string& name, int grade_to_sign, int grade_to_execute);
	AForm(const AForm& obj);
	virtual ~AForm();
	AForm&				operator=(const AForm& rhs);
	const std::string&	getName(void) const;
	bool				getIsSigned(void) const;
	int					getGradeToSign(void) const;
	int					getGradeToExecute(void) const;
	void				beSigned(Bureaucrat& bureaucrat);
	virtual void		execute(Bureaucrat const & executor) const = 0;

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char	*what() const throw()
		{
			return ("grade too high");
		}
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char	*what() const throw()
		{
			return ("grade too low");
		}
	};
	class FormNotSignedException : public std::exception
	{
	public:
		virtual const char	*what() const throw()
		{
			return ("form not signed");
		}
	};
};

std::ostream&	operator<<(std::ostream& os, const AForm& form);

#endif

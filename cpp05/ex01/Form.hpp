#ifndef FORM_HPP
# define FORM_HPP

# include	<iostream>
# include	"Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	name;
	bool				is_signed;
	const int			grade_to_sign;
	const int			grade_to_execute;
public:
	Form();
	Form(const std::string& name, int grade_to_sign, int grade_to_execute);
	Form(const Form& obj);
	~Form();
	Form&				operator=(const Form& rhs);
	const std::string&	getName(void) const;
	bool				getIsSigned(void) const;
	int					getGradeToSign(void) const;
	int					getGradeToExecute(void) const;
	void				beSigned(Bureaucrat& bureaucrat);

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
};

#endif

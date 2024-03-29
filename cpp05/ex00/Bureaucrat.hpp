#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include	<iostream>
# include	<fstream>

class Bureaucrat
{
private:
	const std::string	name;
	int					grade;
public:
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char	*what() const throw()
		{
			return ("Bureaucrat: grade too high");
		}
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char	*what() const throw()
		{
			return ("Bureaucrat: grade too low");
		}
	};

	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& obj);
	~Bureaucrat();
	Bureaucrat&	operator=(const Bureaucrat& rhs);
	const std::string&	getName() const;
	int					getGrade() const;
	void				incrementGrade(void);
	void				decrementGrade(void);

	static const int	highest_grade = 1;
	static const int	lowest_grade = 150;
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif

#include	"Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("no_name"), grade(lowest_grade)
{
	;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name)
{
	if (grade < this->highest_grade)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > this->lowest_grade)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj)
{
	*this = obj;
}

Bureaucrat::~Bureaucrat()
{
	;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& rhs)
{
	const_cast<std::string&>(this->name) = rhs.name;
	this->grade = rhs.grade;
	return (*this);
}

const std::string&	Bureaucrat::getName() const
{
	return (this->name);
}

int	Bureaucrat::getGrade() const
{
	return (this->grade);
}

void	Bureaucrat::incrementGrade(void)
{
	if (this->grade - 1 < this->highest_grade)
		throw Bureaucrat::GradeTooHighException();
	grade--;
}

void	Bureaucrat::decrementGrade(void)
{
	if (this->grade + 1 > this->lowest_grade)
		throw Bureaucrat::GradeTooLowException();
	grade++;
}

void	Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << "." << std::endl;
	}
	
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (os);
}

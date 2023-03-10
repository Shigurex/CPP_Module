#include	"AForm.hpp"

AForm::AForm() : name("no_name"), is_signed(false), grade_to_sign(Bureaucrat::lowest_grade), grade_to_execute(Bureaucrat::lowest_grade)
{
	;
}

AForm::AForm(const std::string& name, int grade_to_sign, int grade_to_execute) : name(name), is_signed(false), grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute)
{
	if (grade_to_sign < Bureaucrat::highest_grade || grade_to_execute < Bureaucrat::highest_grade)
		throw AForm::GradeTooHighException();
	else if (grade_to_sign > Bureaucrat::lowest_grade || grade_to_sign > Bureaucrat::lowest_grade)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& obj) : grade_to_sign(obj.grade_to_sign), grade_to_execute(obj.grade_to_execute)
{
	*this = obj;
}

AForm::~AForm()
{
	;
}

AForm&	AForm::operator=(const AForm& rhs)
{
	const_cast<std::string&>(this->name) = rhs.name;
	this->is_signed = rhs.is_signed;
	const_cast<int&>(this->grade_to_sign) = rhs.grade_to_sign;
	const_cast<int&>(this->grade_to_execute) = rhs.grade_to_execute;
	return (*this);
}

const std::string&	AForm::getName(void) const
{
	return (this->name);
}

bool	AForm::getIsSigned(void) const
{
	return (this->is_signed);
}

int	AForm::getGradeToSign(void) const
{
	return (this->grade_to_sign);
}

int	AForm::getGradeToExecute(void) const
{
	return (this->grade_to_execute);
}

void	AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->grade_to_sign)
		throw AForm::GradeTooLowException();
	this->is_signed = true;
}

std::ostream&	operator<<(std::ostream& os, const AForm& form)
{
	os << "name: " << form.getName() << std::endl;
	if (form.getIsSigned())
		os << "is_signed: true" << std::endl;
	else
		os << "is_signed: false" << std::endl;
	os << "grade_to_sign: " << form.getGradeToSign() << std::endl;
	os << "grade_to_execute: " << form.getGradeToExecute() << std::endl;
	return (os);
}

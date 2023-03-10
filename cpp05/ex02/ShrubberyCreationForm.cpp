#include	"ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("shrubbery creation", ShrubberyCreationForm::grade_to_sign, ShrubberyCreationForm::grade_to_execute), target("no_target")
{
	;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("shrubbery creation", ShrubberyCreationForm::grade_to_sign, ShrubberyCreationForm::grade_to_execute), target(target)
{
	;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj)
{
	*this = obj;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	this->AForm::operator=(rhs);
	const_cast<std::string&>(this->target) = rhs.target;
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::string		file_name(this->target + "_shrubbery");
	std::ofstream	ofs;

	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > ShrubberyCreationForm::grade_to_execute)
		throw AForm::GradeTooLowException();
	ofs.open(file_name);
	if (ofs.fail()) {
		std::cerr << "failed to open file" << std::endl;
		return ;
	}
	ofs << "              |        |       " << std::endl;
	ofs << "    |        | |      | |      " << std::endl;
	ofs << "   | |      |   |    |   |     " << std::endl;
	ofs << "  | | |    |     |  |  |  |    " << std::endl;
	ofs << " |--|--|  |       ||---|---|   " << std::endl;
	ofs << "    |    |         |   |       " << std::endl;
	ofs << "        |     |     |     |    " << std::endl;
	ofs << "       |     | |     |   | |   " << std::endl;
	ofs << "      |------| |------| |   |  " << std::endl;
	ofs << "             | |       |--|--| " << std::endl;
	ofs << "             | |          |    " << std::endl;
	ofs.close();
}

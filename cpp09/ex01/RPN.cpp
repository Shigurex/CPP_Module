#include	"RPN.hpp"

RPN::RPN() : raw_string(EMPTY_STRING)
{
	;
}

RPN::RPN(const std::string raw_string) : raw_string(raw_string)
{
	;
}

RPN::RPN(const RPN& obj)
{
	*this = obj;
}

RPN::~RPN()
{
	;
}

RPN&	RPN::operator=(const RPN& rhs)
{
	this->raw_string = rhs.raw_string;
	return (*this);
}

bool	RPN::isOperator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

int	RPN::execOperator(int value_from, int value_to, char c_operator)
{
	int	value;

	if (!(this->isOperator(c_operator)))
		throw InvalidSyntaxException();
	switch (c_operator)
	{
	case '+':
		if (value_to >= 0 && value_from > INT_MAX - value_to)
			throw OverflowException();
		else if (value_to <= 0 && value_from < INT_MIN - value_to)
			throw UnderflowException();
		value = value_from + value_to;
		break ;
	case '-':
		if (value_to <= 0 && value_from > INT_MAX + value_to)
			throw OverflowException();
		else if (value_to >= 0 && value_from < INT_MIN + value_to)
			throw UnderflowException();
		value = value_from - value_to;
		break;
	case '*':
		if ((value_to > 0 && value_from > INT_MAX / value_to) || (value_to < 0 && value_to > INT_MAX / value_from))
			throw OverflowException();
		else if ((value_to > 0 && value_from < INT_MIN / value_to) || (value_to < 0 && value_to < INT_MIN / value_from))
			throw UnderflowException();
		value = value_from * value_to;
		break ;
	case '/':
		if (value_to == 0)
			throw ZeroDivisionException();
		else if (value_from == INT_MIN && value_to == -1)
			throw OverflowException();
		value = value_from / value_to;
		break ;
	}
	return (value);
}

int	RPN::calculate(void)
{
	std::stack<int>				stack;
	int							value_from;
	int							value_to;
	int							value;
	size_t						size = this->raw_string.size();

	for (size_t i = 0; i < size; i++) {
		if (std::isdigit(this->raw_string[i]))
			stack.push(this->raw_string[i] - '0');
		else if (this->isOperator(this->raw_string[i])) {
			if (stack.size() < 2)
				throw InvalidSyntaxException();
			value_to = stack.top();
			stack.pop();
			value_from = stack.top();
			stack.pop();
			value = execOperator(value_from, value_to, this->raw_string[i]);
			stack.push(value);
		} else if (this->raw_string[i] == ' ')
			continue ;
		else
			throw InvalidSyntaxException();
	}
	if (stack.size() != 1)
		throw InvalidSyntaxException();
	value = stack.top();
	stack.pop();
	return (value);
}

const char	*RPN::InvalidSyntaxException::what() const throw()
{
	return ("Error");
}

const char	*RPN::OverflowException::what() const throw()
{
	return ("Overflow occurred while calculating");
}

const char	*RPN::UnderflowException::what() const throw()
{
	return ("Underflow occurred while calculating");
}

const char	*RPN::ZeroDivisionException::what() const throw()
{
	return ("Zero division occurred calculating");
}

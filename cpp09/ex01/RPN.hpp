#ifndef RPN_HPP
# define RPN_HPP

# include	<stack>
# include	<vector>
# include	<iostream>
# include	<limits>

# define EMPTY_STRING ""

class RPN
{
private:
	std::string			raw_string;
	std::vector<char>	valid_value_vector;

	bool	isOperator(char c);
	int		execOperator(int value_from, int value_to, char c_operator);
public:
	RPN();
	RPN(const std::string raw_string);
	RPN(const RPN& obj);
	~RPN();
	RPN&	operator=(const RPN& rhs);
	void	parse(void);
	int		calculate(void);

	class InvalidSyntaxException : public std::exception
	{
		virtual const char	*what() const throw();
	};

	class OverflowException : public std::exception
	{
		virtual const char	*what() const throw();
	};

	class UnderflowException : public std::exception
	{
		virtual const char	*what() const throw();
	};

	class ZeroDivisionException : public std::exception
	{
		virtual const char	*what() const throw();
	};
};

#endif

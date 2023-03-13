#ifndef SPAN_HPP
# define SPAN_HPP

# include	<algorithm>
# include	<exception>
# include	<vector>
# include	<iostream>

class Span
{
private:
	unsigned int		size;
	std::vector<int>	vector;
public:
	Span();
	Span(unsigned int n);
	Span(const Span& obj);
	~Span();
	Span&			operator=(const Span& rhs);
	void			addNumber(int n);
	unsigned int	shortestSpan(void) const;
	unsigned int	longestSpan(void) const;
	void			addRange(std::vector<int>::iterator it_begin, std::vector<int>::iterator it_end);

	class IndexOutOfRangeException : public std::exception
	{
		virtual const char	*what() const throw();
	};
	class NoSpanException : public std::exception
	{
		virtual const char	*what() const throw();
	};
};

#endif

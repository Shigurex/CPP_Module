#ifndef SPAN_HPP
# define SPAN_HPP

# include	<exception>

class Span
{
private:
	unsigned int	n;
	int				*array;
public:
	Span();
	Span(unsigned int n);
	Span(const Span& obj);
	~Span();
	Span&			operator=(const Span& rhs);
	void			addNumber(int n);
	unsigned int	shortestSpan(void);
	unsigned int	longestSpan(void);

	class IndexOutOfRangeException : public std::exception
	{
		virtual const char	*what() const throw();
	};
};

#endif

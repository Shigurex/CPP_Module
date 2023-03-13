#include	"Span.hpp"

Span::Span() : size(0)
{
	;
}

Span::Span(unsigned int n) : size(n)
{
	;
}

Span::Span(const Span& obj)
{
	*this = obj;
}

Span::~Span()
{
	;
}

Span&	Span::operator=(const Span& rhs)
{
	if (this == &rhs)
		return (*this);
	this->size = rhs.size;
	this->vector = rhs.vector;
	return (*this);
}

void	Span::addNumber(int n)
{
	if (this->vector.size() == this->size)
		throw Span::IndexOutOfRangeException();
	this->vector.push_back(n);
}

unsigned int	Span::shortestSpan(void) const
{
	std::vector<int>			tmp = this->vector;
	std::vector<int>::iterator	tmp_iter = tmp.begin();
	std::vector<int>::iterator	tmp_end_iter = tmp.end();
	unsigned int				shortest_span = std::numeric_limits<unsigned int>::max();
	unsigned int				span;

	if (tmp.size() < 2)
		throw NoSpanException();
	std::sort(tmp_iter, tmp_end_iter);
	for (; tmp_iter + 1 != tmp_end_iter; tmp_iter++) {
		span = *(tmp_iter + 1) - *tmp_iter;
		if (span <= shortest_span)
			shortest_span = span;
	}
	return (shortest_span);
}

unsigned int	Span::longestSpan(void) const
{
	std::vector<int>			tmp = this->vector;
	std::vector<int>::iterator	tmp_first_iter = tmp.begin();
	std::vector<int>::iterator	tmp_end_iter = tmp.end();
	unsigned int				longest_span;

	if (tmp.size() < 2)
		throw NoSpanException();
	std::sort(tmp_first_iter, tmp_end_iter);
	longest_span = *(tmp_end_iter - 1) - *tmp_first_iter;
	return (longest_span);
}

void	Span::addAtOnce(std::vector<int> vector)
{
	std::vector<int>::iterator	it_begin = vector.begin();
	std::vector<int>::iterator	it_end = vector.end();

	if (this->vector.size() + vector.size() > this->size)
		throw Span::SizeTooBigException();
	for (std::vector<int>::iterator it = it_begin; it != it_end; it++) {
		if (this->vector.size() == this->size)
			throw Span::IndexOutOfRangeException();
		this->vector.push_back(*it);
	}
}

const char	*Span::IndexOutOfRangeException::what() const throw()
{
	return ("index out of range");
}

const char	*Span::NoSpanException::what() const throw()
{
	return ("no span found");
}

const char	*Span::SizeTooBigException::what() const throw()
{
	return ("input size too big");
}

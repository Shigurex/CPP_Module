#include	"Span.hpp"

Span::Span() : n(0), array(new int[0])
{
	;
}

Span::Span(unsigned int n) : n(n), array(new int[n])
{
	;
}

Span::Span(const Span& obj)
{
	array = NULL;
	*this = obj;
}

Span::~Span()
{
	delete [] this->array;
}


Span&	Span::operator=(const Span& rhs)
{
	if (this == &rhs)
		return (*this);
	this->n = rhs.n;
	if (this->array)
		delete [] this->array;
	this->array = new int[this->n];
	for (unsigned int i = 0; i < this->n; i++)
		this->array[i] = rhs.array[i];
	return (*this);
}

void	Span::addNumber(int n)
{
	;
}

	unsigned int	shortestSpan(void);
	unsigned int	longestSpan(void);

const char	*Span::IndexOutOfRangeException::what() const throw()
{
	return ("index out of range");
}

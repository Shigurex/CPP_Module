#ifndef ARRAY_HPP
# define ARRAY_HPP

# include	<iostream>
# include	<exception>

template<typename T>
class Array
{
private:
	unsigned int	n;
	T				*array;
public:
	Array() : n(0), array(new T[0])
	{
		;
	};
	Array(unsigned int n) : n(n), array(new T[n])
	{
		;
	};
	Array(const Array& obj)
	{
		array = NULL;
		*this = obj;
	};
	~Array()
	{
		delete [] this->array;
	};
	Array&	operator=(const Array& rhs)
	{
		if (this == &rhs)
			return (*this);
		this->n = rhs.n;
		if (this->array)
			delete [] this->array;
		this->array = new T[this->n];
		for (size_t i = 0; i < this->n; i++)
			this->array[i] = rhs.array[i];
		return (*this);
	};
	T&	operator[](unsigned int n)
	{
		if (n >= this->n)
			throw std::exception();
		return (this->array[n]);
	};
	const T&	operator[](unsigned int n) const
	{
		if (n >= this->n)
			throw std::exception();
		return (this->array[n]);
	};
	unsigned int	size(void) const
	{
		return (this->n);
	}
};

#endif

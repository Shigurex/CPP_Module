#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include	<exception>
# include	<algorithm>

class NotFoundException : public std::exception
{
	public:
		virtual const char	*what() const throw()
		{
			return ("value not found");
		}
};

template<typename T>
typename T::iterator	easyfind(T container, int n)
{
	typename T::iterator	result = std::find(container.begin(), container.end(), n);

	if (result == container.end())
		throw NotFoundException();
	return (result);
}

#endif

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include	<list>
# include	<vector>
# include	<iostream>
# include	<climits>
# include	<ctime>

class PmergeMe
{
private:
	std::vector<int>	vector;
	std::list<int>		list;
public:
	PmergeMe();
	PmergeMe(std::vector<int> vector, std::list<int> list);
	PmergeMe(const PmergeMe& obj);
	~PmergeMe();
	PmergeMe&	operator=(const PmergeMe& rhs);
	void		sortVector(size_t left, size_t right);
	void		sortMergeVector(size_t left, size_t mid, size_t right);
	void		sortInsertVector(size_t left, size_t right);
	void		sortList(size_t left, size_t right);
	void		sortMergeList(std::list<int>::iterator& iter_left, std::list<int>::iterator& iter_mid, std::list<int>::iterator& iter_right);
	void		sortInsertList(std::list<int>::iterator& iter_left, std::list<int>::iterator& iter_right);
	std::string	getVectorStr(std::vector<int> vector);
	void		sort(void);

	static const size_t	subarray_size = 2;
};

#endif

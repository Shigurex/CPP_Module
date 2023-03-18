#include	"PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	;
}

PmergeMe::PmergeMe(std::vector<int> vector, std::list<int> list) : vector(vector), list(list)
{
	;
}

PmergeMe::PmergeMe(const PmergeMe& obj)
{
	*this = obj;
}

PmergeMe::~PmergeMe()
{
	;
}

PmergeMe&	PmergeMe::operator=(const PmergeMe& rhs)
{
	this->vector = rhs.vector;
	this->list = rhs.list;
	return (*this);
}

void	PmergeMe::sortInsertVector(size_t left, size_t right)
{
	size_t	i, j;
	int		tmp;

	for (i = left; i + 1 < right; i++) {
		tmp = this->vector[i + 1];
		for (j = i + 1; j > left && this->vector[j - 1] > tmp; j--)
			this->vector[j] = this->vector[j - 1];
		this->vector[j] = tmp;
	}
}

void	PmergeMe::sortMergeVector(size_t left, size_t mid, size_t right)
{
	std::vector<int>	vector_left(this->vector.begin() + left, this->vector.begin() + mid);
	std::vector<int>	vector_right(this->vector.begin() + mid, this->vector.begin() + right);
	size_t				vector_left_size = vector_left.size();
	size_t				vector_right_size = vector_right.size();
	size_t				left_index = 0, right_index = 0;

	for (size_t i = left; i < right; i++) {
		if (left_index == vector_left_size) {
			this->vector[i] = vector_right[right_index];
			right_index++;
		} else if (right_index == vector_right_size) {
			this->vector[i] = vector_left[left_index];
			left_index++;
		} else if (vector_left[left_index] < vector_right[right_index]) {
			this->vector[i] = vector_left[left_index];
			left_index++;
		} else {
			this->vector[i] = vector_right[right_index];
			right_index++;
		}
	}
}

void	PmergeMe::sortVector(size_t left, size_t right)
{
	size_t	mid = 0;

	if (left >= right)
		return ;
	else if (right - left > this->subarray_size) {
		mid = (left + right) / 2;
		sortVector(left, mid);
		sortVector(mid, right);
		sortMergeVector(left, mid, right);
	} else
		sortInsertVector(left, right);
}

std::string	PmergeMe::getVectorStr(std::vector<int> vector)
{
	std::vector<int>::iterator	iter_begin = vector.begin();
	std::vector<int>::iterator	iter_end = vector.end();
	std::vector<int>::iterator	iter = iter_begin;
	std::string					str;

	while (true) {
		if (iter == iter_end)
			break ;
		str += std::to_string(*iter);
		iter++;
		if (iter != iter_end)
			str += " ";
	}
	return (str);
}

void	PmergeMe::sortInsertList(std::list<int>::iterator& iter_left, std::list<int>::iterator& iter_right)
{
	std::list<int>::iterator	iter, iter_next;
	std::list<int>::iterator	iter_tmp, iter_next_tmp;
	int							tmp;

	iter = iter_left;
	iter_next = iter;
	std::advance(iter_next, 1);
	for (; iter_next != iter_right; iter++, iter_next++) {
		tmp = *iter_next;
		for (iter_next_tmp = iter_next, iter_tmp = iter; iter_next_tmp != iter_left && *iter_tmp > tmp; iter_tmp--, iter_next_tmp--)
			*iter_next_tmp = *iter_tmp;
		*iter_next_tmp = tmp;
	}
}

void	PmergeMe::sortMergeList(std::list<int>::iterator& iter_left, std::list<int>::iterator& iter_mid, std::list<int>::iterator& iter_right)
{
	std::list<int>				list_left(iter_left, iter_mid);
	std::list<int>				list_right(iter_mid, iter_right);
	std::list<int>::iterator	iter_list_left = list_left.begin();
	std::list<int>::iterator	iter_list_right = list_right.begin();
	std::list<int>::iterator	iter;

	size_t	left_index = 0, right_index = 0;
	size_t	list_left_size = list_left.size();
	size_t	list_right_size = list_right.size();

	for (iter = iter_left; iter != iter_right; iter++) {
		if (left_index == list_left_size) {
			*iter = *iter_list_right++;
			right_index++;
		} else if (right_index == list_right_size) {
			*iter = *iter_list_left++;
			left_index++;
		} else if (*iter_list_left < *iter_list_right) {
			*iter = *iter_list_left++;
			left_index++;
		} else {
			*iter = *iter_list_right++;
			right_index++;
		}
	}
}

void	PmergeMe::sortList(size_t left, size_t right)
{
	std::list<int>::iterator	iter_left = list.begin();
	std::list<int>::iterator	iter_right = list.begin();
	std::advance(iter_left, left);
	std::advance(iter_right, right);
	size_t	mid;

	if (left >= right)
		return ;
	else if (right - left > this->subarray_size) {
		mid = (left + right) / 2;
		std::list<int>::iterator	iter_mid = list.begin();
		std::advance(iter_mid, mid);
		sortList(left, mid);
		sortList(mid, right);
		sortMergeList(iter_left, iter_mid, iter_right);
	} else
		sortInsertList(iter_left, iter_right);
}

void	PmergeMe::sort(void)
{
	std::vector<int>	vector_before(this->vector.begin(), this->vector.begin() + this->vector.size());
	std::clock_t		time_start, time_end;
	double				time_vector, time_list;

	time_start = std::clock();
	sortVector(0, vector.size());
	time_end = std::clock();
	time_vector = static_cast<double>(time_end - time_start);
	time_start = std::clock();
	sortList(0, list.size());
	time_end = std::clock();
	time_list = static_cast<double>(time_end - time_start);

	std::cout << "Before:\t" << getVectorStr(vector_before) << std::endl;
	std::cout << "After:\t" << getVectorStr(vector) << std::endl;

	std::cout << "Time to process a range of " << vector.size() << " elements with std::vector:\t" << time_vector << " us" << std::endl;
	std::cout << "Time to process a range of " << list.size() << " elements with std::list:\t" << time_list << " us" << std::endl;
}

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <stdlib.h>
# include <string>
# include <sstream>
# include <ctime>
# include <vector>
# include <list>

# define MILLI 1000

class PmergeMe {
private:
	template <typename T>
	T mergeContainer(T& l, T& r);
	std::vector<unsigned int> mergeSortVector(std::vector<unsigned int>& vec);
	std::list<unsigned int> mergeSortList(std::list<unsigned int>& list);
public:
	PmergeMe(void);
	PmergeMe(const PmergeMe& to_copy);
	PmergeMe &operator=(const PmergeMe& to_copy);
	~PmergeMe(void);

	template <typename T_iter>
	void print(T_iter begin, T_iter end) {
		for (T_iter it = begin; it != end; it++)
			std::cout << *it << " ";
		std::cout<<std::endl;
	}
	
	void sortVector(std::vector<unsigned int>& vec, bool printtime);
	void sortList(std::list<unsigned int>& list, bool printtime);
};

#endif
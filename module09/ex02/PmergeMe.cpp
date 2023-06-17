#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {};
PmergeMe::PmergeMe(const PmergeMe& ref) {
    *this = ref;
}
PmergeMe& PmergeMe::operator=(const PmergeMe& ref) {
	(void)ref;
	return *this;
}
PmergeMe::~PmergeMe(void) {};

void PmergeMe::sortVector(std::vector<unsigned int>& vec, bool printtime)
{
	std::clock_t start = std::clock();
	vec = mergeSortVector(vec);

	double elapsed = static_cast<double>(std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC) * MILLI;

    std::cout << std::fixed;
    std::cout.precision(5);
    if (printtime)
	std::cout   << "Time to process a range of " << vec.size()
		        << " elements with std::vector<unsigned int> : "
		        << elapsed << " ms" << std::endl;
}

void PmergeMe::sortList(std::list<unsigned int>& list, bool printtime)
{
	std::clock_t start = std::clock();

	list = mergeSortList(list);

	double elapsed = static_cast<double>(std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC) * MILLI;

    std::cout << std::fixed;
    std::cout.precision(5);
    if (printtime)
	std::cout   << "Time to process a range of " << list.size()
		        << " elements with std::list<unsigned int> : "
		        << elapsed << " ms" << std::endl;
}

// private
template <typename T>
T PmergeMe::mergeContainer(T& l, T& r)
{
    T merged;

    while (!l.empty() && !r.empty())
	{
        if (l.front() <= r.front())
		{
            merged.push_back(l.front());
            l.erase(l.begin());
        }
		else
		{
            merged.push_back(r.front());
            r.erase(r.begin());
        }
    }

    while (!l.empty())
	{
        merged.push_back(l.front());
        l.erase(l.begin());
    }

    while (!r.empty())
	{
        merged.push_back(r.front());
        r.erase(r.begin());
    }
    return merged;
}

// Vector
std::vector<unsigned int> PmergeMe::mergeSortVector(std::vector<unsigned int>& vec) {
    if (vec.size() <= 1) {
        return vec;
    }

    int mid = vec.size() / 2;
    std::vector<unsigned int> l(vec.begin(), vec.begin() + mid);
    std::vector<unsigned int> r(vec.begin() + mid, vec.end());

    l = mergeSortVector(l);
    r = mergeSortVector(r);

    return mergeContainer(l, r);
}

// List
std::list<unsigned int> PmergeMe::mergeSortList(std::list<unsigned int>& lst) {
    if (lst.size() <= 1) {
        return lst;
    }

    int mid = lst.size() / 2;
	std::list<unsigned int> l;
	std::list<unsigned int> r;

    for (int i = 0; i < mid; i++) {
        l.push_back(lst.front());
        lst.pop_front();
    }
    r = lst;

    l = mergeSortList(l);
    r = mergeSortList(r);

    return mergeContainer(l, r);
}


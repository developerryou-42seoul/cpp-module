#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <ctime>

# define MILLI 1000

class PmergeMe {
private:
	template <typename T>
	void mergeContainer(T& container, T& l, T& r) {
		container.clear();

		while (!l.empty() && !r.empty())
		{
			if (l.front() <= r.front())
			{
				container.push_back(l.front());
				l.erase(l.begin());
			}
			else
			{
				container.push_back(r.front());
				r.erase(r.begin());
			}
		}

		while (!l.empty())
		{
			container.push_back(l.front());
			l.erase(l.begin());
		}

		while (!r.empty())
		{
			container.push_back(r.front());
			r.erase(r.begin());
		}
	}

	template <typename T>
	void insertSort(T& container) {
		typename T::iterator st = container.begin();
		std::advance(st, 1);
		while (st != container.end())
		{
			typename T::iterator it = st;
			while (it != container.begin())
			{
				typename T::iterator prev = it;
				std::advance(prev, -1);
				if (*prev > *it)
					std::iter_swap(prev, it);
				it = prev;
			}
			std::advance(st, 1);
		}
	}

	template <typename T>
	void mergeInsertSort(T& container) {
		if (container.size() <= 1) {
			return ;
		}
		else if (container.size() <= 5) {
			insertSort(container);
			return ;
		}

		int mid = container.size() / 2;
		typename T::iterator it_mid = container.begin();
		std::advance(it_mid, mid);
		T l(container.begin(), it_mid);
		T r(it_mid, container.end());

		mergeInsertSort(l);
		mergeInsertSort(r);
		
		mergeContainer(container, l, r);
	}

public:
	PmergeMe(void) {}
	PmergeMe(const PmergeMe& ref) {
    	*this = ref;
	}
	PmergeMe &operator=(const PmergeMe& ref) {
		(void)ref;
		return *this;
	}
	~PmergeMe(void) {}

	template <typename T_iter>
	void print(T_iter begin, T_iter end) {
		for (T_iter it = begin; it != end; it++)
			std::cout << *it << " ";
		std::cout<<std::endl;
	}

	template <typename T>
	void sort(T& container, bool printtime, std::string type){
		std::clock_t start = std::clock();
		mergeInsertSort(container);

		double elapsed = static_cast<double>(std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC) * MILLI;

		std::cout << std::fixed;
		std::cout.precision(5);
		if (printtime)
		std::cout   << "Time to process a range of " << container.size()
					<< " elements with "<<type<<" : "
					<< elapsed << " ms" << std::endl;
	}
};


#endif
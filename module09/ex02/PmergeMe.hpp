#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
# include <list>
# include <ctime>
# include <iterator>
# include <algorithm>

# define MILLI 1000

typedef std::vector<unsigned int> t_vector;
typedef std::list<unsigned int> t_list;
typedef std::list<t_vector::iterator> t_chain;

const size_t jacobsthal[] = {
	2u, 2u, 6u, 10u, 22u, 42u, 86u, 170u, 342u, 682u, 1366u,
	2730u, 5462u, 10922u, 21846u, 43690u, 87382u, 174762u, 349526u, 699050u,
	1398102u, 2796202u, 5592406u, 11184810u, 22369622u, 44739242u, 89478486u,
	178956970u, 357913942u, 715827882u, 1431655766u, 2863311530u, 5726623062u,
	11453246122u, 22906492246u, 45812984490u, 91625968982u, 183251937962u,
	366503875926u, 733007751850u, 1466015503702u, 2932031007402u, 5864062014806u,
	11728124029610u, 23456248059222u, 46912496118442u, 93824992236886u, 187649984473770u,
	375299968947542u, 750599937895082u, 1501199875790165u, 3002399751580331u,
	6004799503160661u, 12009599006321322u, 24019198012642644u, 48038396025285288u,
	96076792050570576u, 192153584101141152u, 384307168202282304u, 768614336404564608u,
	1537228672809129216u, 3074457345618258432u, 6148914691236516864u
};

class PmergeMe {
private:
	void mergeInsertSort(t_vector::iterator begin, t_vector::iterator end, size_t sizeUnit);
	void mergeInsertSort(t_list::iterator begin, t_list::iterator end, size_t sizeUnit);

	class VectorData
	{
	private:
		const t_vector::iterator begin;
		const t_vector::iterator end;
		const size_t unit_length;
		t_chain mainchain;
		t_chain pend;
		t_vector::iterator new_end;
		size_t container_length;
		size_t group_length;
		bool leftover;
		static bool comp(unsigned int value, const t_vector::iterator& it){
			return value < *it;
		}
	public:
		VectorData(const t_vector::iterator begin, const t_vector::iterator end, const size_t unit_length);
		VectorData(const VectorData& ref);
		VectorData &operator=(const VectorData& ref);
		~VectorData();
		
		bool canPair();
		bool hasLeftover();
		t_vector::iterator getNewEnd();

		void makePairSorted();
		void makeChain();
		void binaryInsert();
		void restruct();
	};

public:
	PmergeMe(void);
	PmergeMe(const PmergeMe& ref);
	PmergeMe &operator=(const PmergeMe& ref);
	~PmergeMe(void);

	void print(t_vector::iterator begin, t_vector::iterator end);
	void sort(t_vector& container, bool printtime);
	void print(t_list::iterator begin, t_list::iterator end);
	void sort(t_list& container, bool printtime);
	
};

#endif
#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(const PmergeMe& ref) {
	*this = ref;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& ref) {
	(void)ref;
	return *this;
}

PmergeMe::~PmergeMe(void) {}

void PmergeMe::print(t_vector::iterator begin, t_vector::iterator end){
	for (t_vector::iterator it = begin; it != end; it++)
		std::cout << *it << " ";
	std::cout<<std::endl;
}

void PmergeMe::print(t_list::iterator begin, t_list::iterator end){
	for (t_list::iterator it = begin; it != end; it++)
		std::cout << *it << " ";
	std::cout<<std::endl;
}

void PmergeMe::sort(t_vector& container, bool printtime){
	std::clock_t start = std::clock();
	mergeInsertSort(container.begin(), container.end(), 1);

	double elapsed = static_cast<double>(std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC) * MILLI;

	std::cout << std::fixed;
	std::cout.precision(5);
	if (printtime)
	std::cout   << "Time to process a range of " << container.size()
				<< " elements with std::vector<unsigned int> : "
				<< elapsed << " ms" << std::endl;
}

void PmergeMe::sort(t_list& container, bool printtime){
	std::clock_t start = std::clock();
	mergeInsertSort(container.begin(), container.end(), 1);

	double elapsed = static_cast<double>(std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC) * MILLI;

	std::cout << std::fixed;
	std::cout.precision(5);
	if (printtime)
	std::cout   << "Time to process a range of " << container.size()
				<< " elements with std::list<unsigned int> : "
				<< elapsed << " ms" << std::endl;
}

void PmergeMe::mergeInsertSort(const t_vector::iterator begin, const t_vector::iterator end, const size_t unit_length){
	VectorData data = VectorData(begin, end, unit_length);
	if (!data.canPair())
		return;

	// pairing
	data.makePairSorted();
	// recursive sorting
	mergeInsertSort(begin, data.getNewEnd(), unit_length * 2);
	// make mainchain, pend
	data.makeChain();
	// binary insert to mainchain
	data.binaryInsert();
	// restruct array
	data.restruct();
}

void PmergeMe::mergeInsertSort(t_list::iterator begin, t_list::iterator end, size_t sizeUnit){
	(void) begin;
	(void) end;
	(void) sizeUnit;
	return;
}

PmergeMe::VectorData::VectorData(const t_vector::iterator begin, const t_vector::iterator end, const size_t unit_length)
: begin(begin), end(end), unit_length(unit_length) {
	container_length = end - begin;
	group_length = unit_length * 2;
	leftover = (container_length % group_length != 0);
	new_end = end;
	if (leftover)
		new_end = new_end - unit_length;
}

PmergeMe::VectorData::~VectorData() {}

PmergeMe::VectorData::VectorData(const PmergeMe::VectorData& ref) 
: begin(ref.begin), end(ref.end), unit_length(ref.unit_length) {
	*this = ref;
}

PmergeMe::VectorData& PmergeMe::VectorData::operator=(const PmergeMe::VectorData& ref) {
	(void)ref;
	return *this;
}

bool PmergeMe::VectorData::canPair() {
	if (group_length <= container_length)
		return true;
	return false;
}

bool PmergeMe::VectorData::hasLeftover() {
	return leftover;
}

t_vector::iterator PmergeMe::VectorData::getNewEnd() {
	return new_end;
}

void PmergeMe::VectorData::makePairSorted() {
	for (t_vector::iterator it = begin; it < new_end; it += unit_length * 2){
		if (*it < *(it + unit_length))
			std::swap_ranges(it, it + unit_length, it + unit_length);
	}
}

void PmergeMe::VectorData::makeChain() {
	mainchain.push_back(begin + unit_length);
	mainchain.push_back(begin);
	for (t_vector::iterator it = begin + group_length; it < new_end; it += group_length){
		mainchain.push_back(it);
		pend.push_back(it + unit_length);
	}
	if (leftover)
		pend.push_back(new_end);
	std::cout<<"makeChain\n";
	std::cout<<"mainchain: ";
	for (t_chain::iterator it = mainchain.begin(); it != mainchain.end(); std::advance(it, 1)){
		std::cout<<**it<<" ";
	}
	std::cout<<"\n";
	std::cout<<"pend: ";
	for (t_chain::iterator it = pend.begin(); it != pend.end(); std::advance(it, 1)){
		std::cout<<**it<<" ";
	}
	std::cout<<"\n";
}

void PmergeMe::VectorData::binaryInsert() {
	std::cout<<"binaryInsert\n";
	size_t idx = 0;
	size_t dist;
	while (!pend.empty()){
		dist = jacobsthal[idx];
		dist = std::min(dist, pend.size());

		t_chain::iterator it_push = pend.begin();
		std::advance(it_push, dist - 1);

		t_chain::iterator it_start_find = mainchain.begin();
		t_chain::iterator it_last_find = mainchain.begin();
		size_t mainchain_length = std::distance(mainchain.begin(), mainchain.end());
		mainchain_length = std::min(mainchain_length, static_cast<size_t>(1 << (idx + 2)));
		std::advance(it_last_find, mainchain_length);
		while (true){
			t_chain::iterator insert_point = std::upper_bound(it_start_find, it_last_find, **it_push, VectorData::comp);
			mainchain.insert(insert_point, *it_push);
			if (it_push == pend.begin())
				break;
			std::advance(it_push, -1);
		}
		for (size_t i = 0; i < dist; i++)
			pend.erase(pend.begin());
		idx++;
	}
}

void PmergeMe::VectorData::restruct() {
	std::cout<<"restruct\n";
	t_vector cache;
	while (!mainchain.empty()){
		t_chain::iterator it_idx = mainchain.begin();
		t_vector::iterator it = *it_idx;
		std::copy(it, it + unit_length, std::back_inserter(cache));
		mainchain.pop_front();
	}
	
	std::cout<<"cache: ";
	for (t_vector::iterator it = cache.begin(); it != cache.end(); std::advance(it, 1)){
		std::cout<<*it<<" ";
	}
	std::cout<<std::endl;
	std::copy(cache.begin(), cache.end(), begin);
}
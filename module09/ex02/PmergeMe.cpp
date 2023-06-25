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

	data.makePairSorted();
	mergeInsertSort(begin, data.getNewEnd(), unit_length * 2);
	data.makeChain();
	data.binaryInsert();
	data.restruct();
}

void PmergeMe::mergeInsertSort(const t_list::iterator begin, const t_list::iterator end, const size_t unit_length){
	ListData data = ListData(begin, end, unit_length);
	if (!data.canPair())
		return;

	data.makePairSorted();
	mergeInsertSort(begin, data.getNewEnd(), unit_length * 2);
	data.makeChain();
	data.binaryInsert();
	data.restruct();
}

// List Data
PmergeMe::ListData::ListData(const t_list::iterator begin, const t_list::iterator end, const size_t unit_length)
: PmergeMe::ListData::AData(unit_length), begin(begin), end(end) {
	container_length = std::distance(begin, end);
	leftover = (container_length % group_length != 0);
	new_end = end;
	if (leftover)
		std::advance(new_end, -unit_length);
}

PmergeMe::ListData::~ListData() {}

PmergeMe::ListData::ListData(const PmergeMe::ListData& ref) 
: PmergeMe::ListData::AData(ref.unit_length), begin(ref.begin), end(ref.end) {
	*this = ref;
}

PmergeMe::ListData& PmergeMe::ListData::operator=(const PmergeMe::ListData& ref) {
	new_end = ref.new_end;
	mainchain = ref.mainchain;
	pend = ref.pend;
	return *this;
}

t_list::iterator PmergeMe::ListData::getNewEnd() {
	return new_end;
}

void PmergeMe::ListData::makePairSorted() {
	for (t_list::iterator it = begin; it != new_end; std::advance(it, unit_length * 2)){
		t_list::iterator next_it = it;
		std::advance(next_it, unit_length);
		if (*it < *next_it)
			std::swap_ranges(it, next_it, next_it);
	}
}

void PmergeMe::ListData::makeChain() {
	t_list::iterator it = begin;
	std::advance(it, unit_length);
	mainchain.push_back(it);
	mainchain.push_back(begin);
	for (std::advance(it, unit_length); it != new_end; std::advance(it, unit_length)){
		mainchain.push_back(it);
		std::advance(it, unit_length);
		pend.push_back(it);
	}
	if (leftover)
		pend.push_back(new_end);
}

void PmergeMe::ListData::binaryInsert() {
	size_t idx = 0;
	size_t dist;
	while (!pend.empty()){
		dist = jacobsthal[idx];
		dist = std::min(dist, pend.size());

		t_chain_list::iterator it_push = pend.begin();
		std::advance(it_push, dist - 1);

		while (true){
			t_chain_list::iterator it_start_find = mainchain.begin();
			t_chain_list::iterator it_last_find = mainchain.begin();
			size_t mainchain_length = std::distance(mainchain.begin(), mainchain.end());
			mainchain_length = std::min(mainchain_length, static_cast<size_t>(1 << (idx + 2)));
			std::advance(it_last_find, mainchain_length);

			t_chain_list::iterator insert_point = std::upper_bound(it_start_find, it_last_find, **it_push, ListData::comp);
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

void PmergeMe::ListData::restruct() {
	t_list cache;
	while (!mainchain.empty()){
		t_chain_list::iterator it_idx = mainchain.begin();
		t_list::iterator it_first = *it_idx;
		t_list::iterator it_last = it_first;
		std::advance(it_last, unit_length);
		std::copy(it_first, it_last, std::back_inserter(cache));
		mainchain.pop_front();
	}
	std::copy(cache.begin(), cache.end(), begin);
}

// Vector Data
PmergeMe::VectorData::VectorData(const t_vector::iterator begin, const t_vector::iterator end, const size_t unit_length)
: PmergeMe::VectorData::AData(unit_length), begin(begin), end(end) {
	container_length = end - begin;
	leftover = (container_length % group_length != 0);
	new_end = end;
	if (leftover)
		new_end = new_end - unit_length;
}

PmergeMe::VectorData::~VectorData() {}

PmergeMe::VectorData::VectorData(const PmergeMe::VectorData& ref) 
: PmergeMe::VectorData::AData(ref.unit_length), begin(ref.begin), end(ref.end) {
	*this = ref;
}

PmergeMe::VectorData& PmergeMe::VectorData::operator=(const PmergeMe::VectorData& ref) {
	new_end = ref.new_end;
	mainchain = ref.mainchain;
	pend = ref.pend;
	return *this;
}

t_vector::iterator PmergeMe::VectorData::getNewEnd() {
	return new_end;
}

void PmergeMe::VectorData::makePairSorted() {
	for (t_vector::iterator it = begin; it != new_end; it += unit_length * 2){
		if (*it < *(it + unit_length))
			std::swap_ranges(it, it + unit_length, it + unit_length);
	}
}

void PmergeMe::VectorData::makeChain() {
	mainchain.push_back(begin + unit_length);
	mainchain.push_back(begin);
	for (t_vector::iterator it = begin + group_length; it != new_end; it += group_length){
		mainchain.push_back(it);
		pend.push_back(it + unit_length);
	}
	if (leftover)
		pend.push_back(new_end);
}

void PmergeMe::VectorData::binaryInsert() {
	size_t idx = 0;
	size_t dist;
	while (!pend.empty()){
		dist = jacobsthal[idx];
		dist = std::min(dist, pend.size());

		t_chain_vector::iterator it_push = pend.begin();
		std::advance(it_push, dist - 1);

		while (true){
			t_chain_vector::iterator it_start_find = mainchain.begin();
			t_chain_vector::iterator it_last_find = mainchain.begin();
			size_t mainchain_length = std::distance(mainchain.begin(), mainchain.end());
			mainchain_length = std::min(mainchain_length, static_cast<size_t>(1 << (idx + 2)));
			std::advance(it_last_find, mainchain_length);
			
			t_chain_vector::iterator insert_point = std::upper_bound(it_start_find, it_last_find, **it_push, VectorData::comp);
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
	t_vector cache;
	while (!mainchain.empty()){
		t_chain_vector::iterator it_idx = mainchain.begin();
		t_vector::iterator it = *it_idx;
		std::copy(it, it + unit_length, std::back_inserter(cache));
		mainchain.pop_front();
	}
	std::copy(cache.begin(), cache.end(), begin);
}

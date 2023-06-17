#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string.h>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack(void) : std::stack<T>() {}
	MutantStack(MutantStack const &ref) : std::stack<T>(ref)
	{ *this = ref; }
	MutantStack &operator=(MutantStack const &ref) {
		std::stack<T>::operator=(ref);
		return (*this);
	}
	~MutantStack() {}


	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin(void) {
		return this->c.begin();
	}
	iterator end(void) {
		return this->c.end();
	}
};
#endif

#include "span.hpp"

Span::Span(void) : _size(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Span::Span(unsigned int N) : _size(N)
{
	std::cout << "Constructor with N called" << std::endl;
}

Span::Span(Span &ref) : _size(ref._size)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_vector = ref._vector;
}

Span& Span::operator=(Span &ref)
{
	std::cout << "Assignment operator called" << std::endl;
	this->_size = ref._size;
	this->_vector = ref._vector;
	return (*this);
}

Span::~Span()
{
	std::cout << "Destructor called" << std::endl;
}

void	Span::addNumber(int number)
{
	if (_vector.size() == _size)
		throw Span::VectorIsFulled();
	_vector.push_back(number);
}

int	randomInt()
{
	struct timespec specific_time;
    long millsec;
    clock_gettime(CLOCK_REALTIME, &specific_time);
    millsec = specific_time.tv_nsec;

	static unsigned int seed = 0;
	srand(millsec + (seed++));
	
	return (rand());
}

void	Span::addManyNumber(void)
{
	size_t	start;

	start = _vector.size();
	while (start < _size)
	{
		_vector.push_back(randomInt());
		start++;
	}
}

long long int Span::shortestSpan(void) const
{
	if (_vector.empty())
		throw Span::VectorIsEmpty();
	else if (_vector.size() == 1)
		throw Span::VectorSizeIsOne();

	std::vector<int> copy = _vector;
	std::sort(copy.begin(), copy.end());
	std::vector<int>::iterator it = ++copy.begin();
	long long int ans = static_cast<long long int>(*it - *(it-1));

	while (it != copy.end())
	{
		if (static_cast<long long int>(*it - *(it-1)) < ans)
			ans = static_cast<long long int>(*it - *(it-1));
		it++;
	}
	return (ans);
}

long long int Span::longestSpan(void) const
{
	if (_vector.empty())
		throw Span::VectorIsEmpty();
	else if (_vector.size() == 1)
		throw Span::VectorSizeIsOne();

	std::vector<int> copy = _vector;
	std::sort(copy.begin(), copy.end());

	return (static_cast<long long int>(copy.back() - copy.front()));
}

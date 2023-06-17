#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# define RAND 2147483647

class Span
{
private:
	unsigned int _size;
	std::vector<int> _vector;
public:
	Span(void);
	Span(unsigned int N);
	Span(Span &ref);
	Span& operator=(Span &ref);
	~Span();

	void	addNumber(int number);
	void	addManyNumber(void);
	long long int shortestSpan(void) const;
	long long int longestSpan(void) const;

	class VectorIsFulled : public std::exception
	{
		public:
		char const * what() const throw()
		{
			return "Vector is Fulled";
		}
	};

	class VectorIsEmpty : public std::exception
	{
		public:
		char const * what() const throw()
		{
			return "Vector is Empty";
		}
	};

	class VectorSizeIsOne : public std::exception
	{
		public:
		char const * what() const throw()
		{
			return "Vector size is One";
		}
	};
};

#endif

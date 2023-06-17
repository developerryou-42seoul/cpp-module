#include <iostream>

template <typename T>
int* easyfind(T &vector, int num)
{
	typename T::iterator it;

	it = std::find(vector.begin(), vector.end(), num);
	if (it == vector.end())
		return (NULL);
	return (&(*it));
}


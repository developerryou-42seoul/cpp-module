#include <iostream>
#include "iter.hpp"

template <typename T>
void plus(T &a)
{
	a++;
}

template <typename T>
void minus(T &a)
{
	a--;
}

int main(void)
{
	int arr1[] = {1, 2, 4, 5, 7, 8};
	char arr2[] = {'a', 'b', 'z', 'y'};

	print(arr1, 6);
	print(arr2, 4);
	iter(arr1, 6, plus);
	iter(arr2, 4, minus);
	print(arr1, 6);
	print(arr2, 4);
	
	return 0;
}

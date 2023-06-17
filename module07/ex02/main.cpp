#include "Array.hpp"
#include <string>
#include <iostream>

int main()
{
	std::cout << "Create array of size 5" << std::endl;
	Array<int> arr(5);
	Array<int> arr_copy = arr;

	std::cout << "arr: ";
	for (int i = 0; i < 5; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "arr_copy: ";
	for (int i = 0; i < 5; i++) {
		std::cout << arr_copy[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Change element in arr" << std::endl;
	arr[1] = 1;
	std::cout << "arr: ";
	for (int i = 0; i < 5; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "arr_copy: ";
	for (int i = 0; i < 5; i++) {
		std::cout << arr_copy[i] << " ";
	}
	std::cout << std::endl << std::endl;


	// Try exeption
	std::cout << "Try out of range index" << std::endl;
	try {
		std::cout << arr[1000];
	} catch (std::exception& e) {
		std::cout << "Too large index" << std::endl;
	}

	std::cout << std::endl << "Try to read value with []" << std::endl;
	try {
		const Array<int> a(5);
		std::cout << "Can read: " << a[0] << std::endl;
		// a[1] = 2;  compile time error
	} catch (std::exception& e) {
		std::cout << "Can't write" << std::endl;
	}

	return 0;
}

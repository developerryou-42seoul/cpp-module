#ifndef ITRE_HPP
# define ITRE_HPP

template <typename T>
void iter(T* arr, int len, void (*f)(T&)) {
	for (int i = 0;i<len;i++) {
		f(arr[i]);
	}
}

template <typename T>
void print(T* arr, int len) {
	for (int i = 0;i<len;i++) {
		std::cout<<arr[i];
		if (i != len - 1)
			std::cout<<' ';
	}
	std::cout<<std::endl;
}

#endif
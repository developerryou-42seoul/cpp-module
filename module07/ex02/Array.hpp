#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template<typename T>
class Array {

private:
	int _len;
public:
	T* arr;

	Array() {
		arr = NULL;
		_len = 0;
	}

	Array(int n) {
		if (n <= 0)
		{
			arr = NULL;
			_len = 0;
		} 
		else 
		{
			arr = new T[n];
			for (int i = 0;i<n;i++) {
				arr[i] = 0;
			}
			_len = n;
		}
	}

	Array(const Array &ref) {
		*this = ref;
	}

	Array& operator =(const Array &ref) {
		if (arr != NULL) {
			delete [] arr;
		}
		_len = ref._len;
		if (_len > 0)
		{
			arr = new T[_len];
			for (int i = 0;i<_len;i++) {
				arr[i] = ref.arr[i];
			}
		}
		return (*this);
	}

	~Array() {
		if (arr != NULL) {
			delete [] arr;
		}
	}

	T& operator[](int n) {
		if (0 <= n && n < _len)
			return arr[n];
		else 
			throw std::exception();
	}

	const T& operator[](int n) const {
		if (0 <= n && n < _len)
			return arr[n];
		else
			throw std::exception();
	}

	int size() const {
		return _len;
	}
};

#endif
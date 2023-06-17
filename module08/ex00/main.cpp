#include "easyfind.hpp"
#include <vector>
#include <algorithm>

int	main(void)
{
	{
		int	* find;
		
		std::vector<int> arr;
		arr.push_back(4);
		arr.push_back(3);
		arr.push_back(2);
		arr.push_back(1);
		find = easyfind(arr, 2);
		if (find == NULL)
			std::cout << "Cannot Find" << std::endl;
		else
			std::cout << "Find : " << *find << std::endl;
	}

	{
		int	* find;
		std::vector<int> arr2;
		arr2.push_back(4);
		arr2.push_back(3);
		arr2.push_back(2);
		arr2.push_back(1);

		find = easyfind(arr2, 97);
		if (find == NULL)
			std::cout << "Cannot Find" << std::endl;
		else
			std::cout << "Find : " << *find << std::endl;

	}

	return (0);
}

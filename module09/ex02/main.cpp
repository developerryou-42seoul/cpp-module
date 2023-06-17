#include "PmergeMe.hpp"

void panic(void)
{
    std::cout<<"Error"<<std::endl;
    exit(1);
}

int	main(int argc, char **argv)
{
    if (argc == 1)
	    return (0);
    
    PmergeMe pmerge;

    for (int i = 1; i < argc; i++)
        if (std::string(argv[i]).find_first_not_of("0123456789 ") != std::string::npos)
            panic();

    std::vector<unsigned int> vec;
    for (int i = 1; i < argc; i++)
        vec.push_back(std::stol(argv[i]));

    std::list<unsigned int> list;
    for (int i = 1; i < argc; i++)
        list.push_back(std::stol(argv[i]));

    std::vector<unsigned int> temp = vec;
    std::cout<<"Before:\t"; pmerge.print(temp.begin(), temp.end());
    pmerge.sortVector(temp, false);
    std::cout<<"After:\t"; pmerge.print(temp.begin(), temp.end());

    pmerge.sortVector(vec, true);
    pmerge.sortList(list, true);

	return (0);
}

#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
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
    {
        unsigned int item;
        std::stringstream ss(argv[i]);
        ss >> item;
        vec.push_back(item);
    }

    std::list<unsigned int> lst;
    for (int i = 1; i < argc; i++)
    {
        unsigned int item;
        std::stringstream ss(argv[i]);
        ss >> item;
        lst.push_back(item);
    }
    
    std::cout<<"Before:\t";
    pmerge.print(vec.begin(), vec.end());


    std::vector<unsigned int> vec_temp = vec;
    pmerge.sort(vec_temp, false, "std::vector<unsigned int>");
    std::cout<<"After:\t";
    pmerge.print(vec_temp.begin(), vec_temp.end());

/*  for test
    std::vector<unsigned int> vec_temp = vec;
    pmerge.sort(vec_temp, false, "std::vector<unsigned int>");
    std::cout<<"After sorting std::vector<unsigned int> : ";
    pmerge.print(vec_temp.begin(), vec_temp.end());

    std::list<unsigned int> lst_temp = lst;
    pmerge.sort(lst_temp, false, "std::list<unsigned int>  ");
    std::cout<<"After sorting std::list<unsigned int>   : ";
    pmerge.print(lst_temp.begin(), lst_temp.end());
*/

    pmerge.sort(vec, true, "std::vector<unsigned int>");
    pmerge.sort(lst, true, "std::list<unsigned int>  ");

	return (0);
}
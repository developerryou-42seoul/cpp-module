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

void checkSorted(t_vector& vec)
{
    bool isSorted = true;
    t_vector::iterator it = vec.begin();
    t_vector::iterator next_it = it;
    next_it++;
    while (next_it != vec.end()) {
        if (*it > *next_it) {
            isSorted = false;
            break;
        }
        it++;
        next_it++;
    }
    if (isSorted)
        std::cout<<"vector is sorted\n";
    else
        std::cout<<"vector is NOT sorted\n";
}

void checkSorted(t_list& lst)
{
    bool isSorted = true;
    t_list::iterator it = lst.begin();
    t_list::iterator next_it = it;
    next_it++;
    while (next_it != lst.end()) {
        if (*it > *next_it) {
            isSorted = false;
            break;
        }
        it++;
        next_it++;
    }
    if (isSorted)
        std::cout<<"list is sorted\n";
    else
        std::cout<<"list is NOT sorted\n";
}

void submit(PmergeMe& pmerge, t_vector& vec, t_list& lst)
{
    pmerge.sort(vec, true);
    pmerge.sort(lst, true);
}

void test(PmergeMe& pmerge, t_vector& vec, t_list& lst)
{
    // for test
    pmerge.sort(vec, false);
    std::cout<<"After sorting t_vector : ";
    pmerge.print(vec.begin(), vec.end());

    pmerge.sort(lst, false);
    std::cout<<"After sorting t_list   : ";
    pmerge.print(lst.begin(), lst.end());
}


int	main(int argc, char **argv)
{
    if (argc <= 1)
	    return (0);
    
    PmergeMe pmerge;

    for (int i = 1; i < argc; i++)
        if (std::string(argv[i]).find_first_not_of("0123456789 ") != std::string::npos)
            panic();

    t_vector vec;
    for (int i = 1; i < argc; i++)
    {
        unsigned int item;
        std::stringstream ss(argv[i]);
        ss >> item;
        vec.push_back(item);
    }

    t_list lst;
    for (int i = 1; i < argc; i++)
    {
        unsigned int item;
        std::stringstream ss(argv[i]);
        ss >> item;
        lst.push_back(item);
    }
    
    std::cout<<"Before:\t";
    pmerge.print(vec.begin(), vec.end());

    t_vector vec_temp = vec;
    pmerge.sort(vec_temp, false);
    std::cout<<"After:\t";
    pmerge.print(vec_temp.begin(), vec_temp.end());

    submit(pmerge, vec, lst);
    //test(pmerge, vec, lst);
    //checkSorted(vec);
    //checkSorted(lst);
	return (0);
}
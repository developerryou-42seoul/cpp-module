#include "PhoneBook.hpp"

void PhoneBook::set_index(int i)
{
	now_idx = i;
}

void PhoneBook::add_contact()
{
	contacts[now_idx % 8].add();
	now_idx++;
}

void PhoneBook::search_contact()
{
	if (now_idx == 0)
		std::cout<<"PhoneBook is empty."<<std::endl;
	else
	{
		std::cout<< "     index"<<"|"
		<<"first name"<<"|"
		<<" last name"<<"|"
		<<"  nickname"<<"|"
		<<std::endl;

		for(int i=0;i<now_idx && i<8;i++)
		{
			std::cout<<"         "<<i+1<<"|";
			contacts[i].print();
		}
		std::cout<<"Enter Index : ";
		int number;
		std::cin>>number;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout<<"Wrong Index"<<std::endl;
			return;
		}
		number--;
		if (number <= 7 && number >= 0 && number < now_idx)
			contacts[number].printAll();
		else
		{
			std::cout<<"Wrong Index"<<std::endl;
			return;
		}
	}
}
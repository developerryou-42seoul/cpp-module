# include <iostream>
# include <string>
# include "PhoneBook.hpp"

int main(void)
{
	PhoneBook phoneBook;
	phoneBook.set_index(0);

	while(true)
	{
		std::cout<<"Input your command (ADD, SEARCH, EXIT)"<<std::endl;
		std::string cmd;
		std::cin>>cmd;
		if (cmd == "ADD")
		{
			phoneBook.add_contact();
		}
		else if (cmd == "SEARCH")
		{
			phoneBook.search_contact();
		}
		else if (cmd == "EXIT")
		{
			break;
		}
		else if (std::cin.eof())
		{
			break;
		}
		else
		{
			std::cout<<"command not found"<<std::endl;
		}
		std::cout<<std::endl;
	}
	return (0);
}
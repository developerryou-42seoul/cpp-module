#include "Contact.hpp"

std::string truncate(std::string str)
{
	if (str.size()>10)
	{
		std::string new_str;
		new_str = str.substr(0, 9);
		new_str+='.';
		return new_str;
	}
	else
		return str;
}

void Contact::print(){
	std::cout<<std::right<<std::setw(10)<<truncate(firstname);
	std::cout<<"|";
	std::cout<<std::right<<std::setw(10)<<truncate(lastname);
	std::cout<<"|";
	std::cout<<std::right<<std::setw(10)<<truncate(nickname);
	std::cout<<"|";
	std::cout<<std::endl;
}

void Contact::printAll()
{
	std::cout<<"first name : "<<firstname<<std::endl;
	std::cout<<"last name : "<<lastname<<std::endl;
	std::cout<<"nickname : "<<nickname<<std::endl;
	std::cout<<"phone number : "<<phonenumber<<std::endl;
	std::cout<<"darkest secret : "<<darkestsecret<<std::endl;
}

void Contact::add(){
	std::cout<<"Input First name : ";
	std::cin>>firstname;
	std::cout<<"Input Last name : ";
	std::cin>>lastname;
	std::cout<<"Input Nickname : ";
	std::cin>>nickname;
	std::cout<<"Input Phone number : ";
	std::cin>>phonenumber;
	std::cout<<"Input Darkest secret : ";
	std::cin>>darkestsecret;
}

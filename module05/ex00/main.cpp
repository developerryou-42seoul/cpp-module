#include <iostream>
#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat anne("Anne", 50);
		std::cout<<anne<<std::endl;
		anne.increaseGrade();
		std::cout<<anne<<std::endl;
		anne.decreaseGrade();
		std::cout<<anne<<std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr<<e.what()<<std::endl;
	}

	try
	{
		Bureaucrat mike("mike", 1149);
	}
	catch(const std::exception& e)
	{
		std::cerr<<e.what()<<std::endl;
	}

	try
	{
		Bureaucrat andy("andy", -2);
	}
	catch(const std::exception& e)
	{
		std::cerr<<e.what()<<std::endl;
	}

	try
	{
		
		Bureaucrat kal("kal", 1);
		std::cout<<kal<<std::endl;
		kal.increaseGrade();
		std::cout<<kal<<std::endl;
		kal.increaseGrade();
		std::cout<<kal<<std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr<<e.what()<<std::endl;
	}

	try
	{
		Bureaucrat jeny("jeny", 148);
		std::cout<<jeny<<std::endl;
		jeny.decreaseGrade();
		std::cout<<jeny<<std::endl;
		jeny.decreaseGrade();
		std::cout<<jeny<<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr<<e.what()<<std::endl;
	}
	return (0);
}
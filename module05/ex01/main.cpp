#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		//Form project1("project 1", 1000, -3);
		Form project2("project 2", 150, -1);
	}
	catch(const std::exception& e)
	{
		std::cerr<<e.what()<<std::endl;
	}
	
	try
	{
		Bureaucrat human("jeny", 3);
		std::cout<<human<<std::endl;

		Form project1("project 1", 5, 3);
		std::cout<<project1<<std::endl;

		human.signForm(project1);
		std::cout<<std::endl;

		std::cout<<project1<<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr<<e.what()<<std::endl;
	}
	try
	{
		Bureaucrat human("tony", 3);
		std::cout<<human<<std::endl;

		Form project2("project 2", 1, 3);
		std::cout<<project2<<std::endl;

		human.signForm(project2);
		std::cout<<std::endl;

		std::cout<<project2<<std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr<<e.what()<<std::endl;
	}

	return (0);
}
#include <iostream>

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

int main(void)
{
	try
	{
		Intern intern1;
		AForm *form;

		form = intern1.makeForm("RobotomyRequestForm", "mike Robot");
		std::cout << form->getName() << std::endl;
		std::cout << form->getTarget() << std::endl;

		std::cout << *form << std::endl;

		Bureaucrat tony("tony", 30);
		tony.signForm(*form);
		tony.executeForm(*form);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Intern intern2;
		AForm *form;	
		form = intern2.makeForm("wrongForm", "wrong");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
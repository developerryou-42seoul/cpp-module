#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	try
	{
		//AForm meta();
		Bureaucrat jeny("jeny", 50);
		Bureaucrat tony("tony", 30);
		ShrubberyCreationForm shrubbery("tree");
		RobotomyRequestForm robotomy("car");
		PresidentialPardonForm presidential("puppy");

		std::cout << jeny << std::endl;
		std::cout << tony << std::endl;

		std::cout << shrubbery << std::endl;
		std::cout << robotomy << std::endl;
		std::cout << presidential << std::endl;

		tony.signForm(shrubbery);
		tony.signForm(robotomy);
		tony.signForm(presidential);

		std::cout<<std::endl;

		jeny.executeForm(shrubbery);
		jeny.executeForm(robotomy);
		jeny.executeForm(presidential);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
	for(int i = 0; i < 3; i++)
		forms[i] = 0;
}

Intern::~Intern()
{
	for(int i = 0; i < 3; i++)
		if (forms[i] != 0)
			delete forms[i];
}

Intern::Intern(const Intern &intern)
{
	if (intern.forms[0] != 0)
		forms[0] = new ShrubberyCreationForm(intern.forms[0]->getTarget());
	if (intern.forms[1] != 0)
		forms[1] = new RobotomyRequestForm(intern.forms[1]->getTarget());
	if (intern.forms[2] != 0)
		forms[2] = new PresidentialPardonForm(intern.forms[2]->getTarget());
}

Intern &Intern::operator=(const Intern &intern)
{
	for(int i = 0; i < 3; i++)
		if (forms[i] != 0)
			delete forms[i];
	if (intern.forms[0] != 0)
		forms[0] = new ShrubberyCreationForm(intern.forms[0]->getTarget());
	if (intern.forms[1] != 0)
		forms[1] = new RobotomyRequestForm(intern.forms[1]->getTarget());
	if (intern.forms[2] != 0)
		forms[2] = new PresidentialPardonForm(intern.forms[2]->getTarget());
	return (*this);
}

AForm* Intern::makeForm(const std::string formName, const std::string formTarget)
{
	for(int i = 0; i < 3; i++)
		if (forms[i] != 0)
			delete forms[i];
	forms[0] = new ShrubberyCreationForm(formTarget);
	forms[1] = new RobotomyRequestForm(formTarget);
	forms[2] = new PresidentialPardonForm(formTarget);

	for(int i=0; i<3; i++)
	{
		if (formName == forms[i]->getName())
			return (forms[i]);
	}
	throw UnknownForm();
}

const char* Intern::UnknownForm::what() const throw()
{
	return ("Intern :: unknown form name Exception");
}

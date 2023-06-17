#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", "none", 72, 45)
{}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", target, 72, 45)
{}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &ref) : AForm("RobotomyRequestForm", ref.getTarget(), 72, 45)
{}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &ref)
{
	(void)ref;
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (getIsSigned() == false)
		throw NotSignedException();
	if (getExecuteGrade() < executor.getGrade())
		throw NotPermittedException();
	robotomize();
}

void RobotomyRequestForm::robotomize() const 
{
	std::cout << "Drrrrrrrr... Drrrrrr... Drr!" << std::endl;

	srand((unsigned int)time(NULL));
	int rd = rand() % 2;

	if (rd == 0)
	{
		std::cout<<getTarget()<<" has become a robot."<<std::endl;
	}
	else
	{
		std::cout<<getTarget()<<" robotomy Failed."<<std::endl;
	}
}

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", "none", 25, 5)
{}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", target, 25, 5)
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ref) : AForm("PresidentialPardonForm", ref.getTarget(), 25, 5)
{}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &ref)
{
	(void)ref;
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (getIsSigned() == false)
		throw NotSignedException();
	if (getExecuteGrade() < executor.getGrade())
		throw NotPermittedException();
	pardon();
}

void PresidentialPardonForm::pardon() const 
{
	std::cout<<getTarget()<<" has been pardoned by Zafod Beeblebrox."<<std::endl;
}

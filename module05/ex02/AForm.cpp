# include "AForm.hpp"

AForm::AForm() : name("undefined"), target("none"), isSigned(false), signGrade(150), executeGrade(150)
{}

AForm::AForm(std::string name, std::string target, int signGrade, int executeGrade) : name(name), target(target), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
	if (signGrade < 1)
		throw GradeTooHighException();

	else if (signGrade > 150)
		throw GradeTooLowException();

	if (executeGrade < 1)
		throw GradeTooHighException();

	else if (executeGrade > 150)
		throw GradeTooLowException();
}

AForm::~AForm()
{}

AForm::AForm(const AForm &ref) : name(ref.name), target(ref.target), isSigned(ref.isSigned), signGrade(ref.signGrade), executeGrade(ref.executeGrade)
{}

AForm& AForm::operator=(const AForm &ref)
{
	this->isSigned = ref.isSigned;
	return (*this);
}

std::string AForm::getName() const
{
	return (name);
}
std::string AForm::getTarget() const
{
	return (target);
}
bool AForm::getIsSigned() const
{
	return (isSigned);
}
int AForm::getSignGrade() const
{
	return (signGrade);
}
int AForm::getExecuteGrade() const
{
	return (executeGrade);
}

void AForm::beSigned(Bureaucrat const & signer)
{
	if (signer.getGrade() <= signGrade)
		isSigned = true;
	else
		throw GradeTooLowException();
}

void AForm::execute(Bureaucrat const & executor) const 
{
	(void)executor;
}

const char* AForm::GradeTooHighException::what(void) const throw()
{
	return ("AForm :: Grade Too High Exception");
}

const char* AForm::GradeTooLowException::what(void) const throw()
{
	return ("AForm :: Grade Too Low Exception");
}

const char* AForm::NotSignedException::what(void) const throw()
{
	return ("AForm :: Not Signed Exception");
}

const char* AForm::NotPermittedException::what(void) const throw()
{
	return ("AForm :: Not Permitted Exception");
}

std::ostream& operator<<(std::ostream &out, const AForm &ref)
{
	out<<"Form name : "<<ref.getName()<<std::endl
	<<"Target name : "<<ref.getTarget()<<std::endl
	<<"IsSigned : "<<std::boolalpha<<ref.getIsSigned()<<std::endl
	<<"Sign grade : "<<ref.getSignGrade()<<std::endl
	<<"Execute grade : "<<ref.getExecuteGrade()<<std::endl;
	return (out);
}

# include "Form.hpp"

Form::Form() : name("undefined"), isSigned(false), signGrade(150), executeGrade(150)
{}

Form::Form(std::string name,int signGrade, int executeGrade) : name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
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

Form::~Form()
{}

Form::Form(const Form &ref) : name(ref.name), isSigned(ref.isSigned), signGrade(ref.signGrade), executeGrade(ref.executeGrade)
{}

Form& Form::operator=(const Form &ref)
{
	this->isSigned = ref.isSigned;
	return (*this);
}

void Form::beSigned(Bureaucrat &target)
{
	if (target.getGrade() <= signGrade)
		isSigned = true;
	else
		throw GradeTooLowException();
}

std::string Form::getName() const
{
	return (name);
}
bool Form::getIsSigned() const
{
	return (isSigned);
}
int Form::getSignGrade() const
{
	return (signGrade);
}
int Form::getExecuteGrade() const
{
	return (executeGrade);
}

const char* Form::GradeTooHighException::what(void) const throw()
{
	return ("Form :: Grade Too High Exception");
}

const char* Form::GradeTooLowException::what(void) const throw()
{
	return ("Form :: Grade Too Low Exception");
}

std::ostream& operator<<(std::ostream &out, const Form &ref)
{
	out<<"Form name : "<<ref.getName()<<std::endl
	<<"IsSigned : "<<std::boolalpha<<ref.getIsSigned()<<std::endl
	<<"Sign grade : "<<ref.getSignGrade()<<std::endl
	<<"Execute grade : "<<ref.getExecuteGrade()<<std::endl;
	return (out);
}

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name("undifined"), grade(1)
{}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();

	else if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat::Bureaucrat(const Bureaucrat &ref) : name(ref.name), grade(ref.grade)
{}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &ref)
{
	this->grade = ref.grade;
	return (*this);
}

std::string Bureaucrat::getName() const
{
	return (name);
}

int Bureaucrat::getGrade() const
{
	return (grade);
}

void Bureaucrat::increaseGrade()
{
	if (grade > 1)
		grade = grade - 1;
	else
		throw GradeTooHighException();
}

void Bureaucrat::decreaseGrade()
{
	if (grade < 150)
		grade = grade + 1;
	else
		throw GradeTooLowException();
}

void Bureaucrat::signForm(Form &form)
{
	if (form.getIsSigned() == true)
	{
		std::cout<<name<< " couldn’t sign "<<form.getName()<<" because "<<form.getName()<<" already signed."<<std::endl;
	}
	else
	{
		try
		{
			form.beSigned(*this);
			std::cout<<name<<" signed "<<form.getName()<<std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout<<name<< " couldn’t sign "<<form.getName()<<" because grade is low."<<std::endl;
		}
	}
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Bureaucrat :: Grade Too High Exception");
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Bureaucrat :: Grade Too Low Exception");
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat &ref)
{
	out<<ref.getName()<<", bureaucrat grade "<<ref.getGrade()<<std::endl;
	return (out);
}

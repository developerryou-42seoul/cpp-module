#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
	const std::string name;
	bool isSigned;
	const int signGrade;
	const int executeGrade;
public:
	Form();
	Form(std::string name,int signGrade, int executeGrade);
	~Form();
	Form(const Form &ref);
	Form& operator=(const Form &ref);

	void beSigned(Bureaucrat &target);

	std::string getName() const;
	bool getIsSigned() const;
	int getSignGrade() const;
	int getExecuteGrade() const;

	class GradeTooHighException : public std::exception {
	public:
		const char* what(void) const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		const char* what(void) const throw();
	};
};

std::ostream& operator<<(std::ostream &out, const Form &ref);

#endif
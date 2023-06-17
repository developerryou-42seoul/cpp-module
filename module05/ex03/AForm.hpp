#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
	const std::string name;
	const std::string target;
	bool isSigned;
	const int signGrade;
	const int executeGrade;
public:
	AForm();
	AForm(std::string name, std::string target, int signGrade, int executeGrade);
	virtual ~AForm() = 0;
	AForm(const AForm &ref);
	AForm& operator=(const AForm &ref);

	std::string getName() const;
	std::string getTarget() const;
	bool getIsSigned() const;
	int getSignGrade() const;
	int getExecuteGrade() const;

	void beSigned(Bureaucrat const & signer);
	virtual void execute(Bureaucrat const & executor) const;

	class GradeTooHighException : public std::exception {
	public:
		const char* what(void) const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		const char* what(void) const throw();
	};
	class NotSignedException : public std::exception {
	public:
		const char* what(void) const throw();
	};
	class NotPermittedException : public std::exception {
	public:
		const char* what(void) const throw();
	};
};

std::ostream& operator<<(std::ostream &out, const AForm &ref);

#endif
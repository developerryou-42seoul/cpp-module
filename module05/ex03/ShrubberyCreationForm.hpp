#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"
#include <fstream>
#include <iostream>

// sign 145, exec 137
class ShrubberyCreationForm : public AForm
{
private:
	void makeTree() const;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	virtual ~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &ref);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &ref);

	virtual void execute(Bureaucrat const &executor) const;
};

#endif
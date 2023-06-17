#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <cstdlib> 
# include <ctime>

// sign 72, exec 45
class RobotomyRequestForm : public AForm
{
private:
	void robotomize() const;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	virtual ~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm &ref);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &ref);

	virtual void execute(Bureaucrat const &executor) const;
};

#endif
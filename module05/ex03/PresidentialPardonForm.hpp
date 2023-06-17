#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"

// sign 25, exec 5
class PresidentialPardonForm : public AForm
{
private:
	void pardon() const;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	virtual ~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm &ref);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &ref);

	virtual void execute(Bureaucrat const &executor) const;
};

#endif
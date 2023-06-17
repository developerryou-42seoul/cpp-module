#ifndef INTERN_HPP
#define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class Intern
{
private:
	AForm *forms[3];
public:
	Intern(void);
	~Intern(void);
	Intern(const Intern &intern);
	Intern& operator=(const Intern &intern);

	AForm* makeForm(std::string formName, std::string fromTarget);

	class UnknownForm : public std::exception {
	public:
		const char *what(void) const throw();
	};
};

#endif

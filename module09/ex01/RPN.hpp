#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <exception>
# include <stack>

# define ERR_ARG "invalid number of arguments"
# define ERR_ARG_INVALID "Error"

class RPN {
private:

public:
	RPN(void);
	RPN(const RPN &ref);
	RPN &operator=(const RPN &ref);
	~RPN(void);

	long long calculate(const std::string& arg);
	bool isValid(const std::string& arg);

	class RPNException : public std::exception {
		public:
			virtual const char* what() const throw();  
	};
};

#endif
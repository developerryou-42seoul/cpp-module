#include "RPN.hpp"

RPN::RPN(void) {};
RPN::RPN(const RPN &ref) {
    *this = ref;
}
RPN& RPN::operator=(const RPN &ref) {
	(void)ref;
    return *this;
}
RPN::~RPN(void) {};

bool RPN::isValid(const std::string& arg)
{
    if (arg.find_first_not_of("0123456789+-/* ") == std::string::npos)
	    return true;
	return false;
}

long long RPN::calculate(const std::string& arg)
{
    std::stack<int> temp;
    size_t index = 0;
    bool flag = true;

    while (index < arg.length())
    {
        char ch = arg[index];

        if (flag)
        {
            if (!(('0' <= ch && ch <= '9') || (ch == '+' || ch == '-' || ch == '/' || ch == '*')))
                throw RPNException();
        }
        else
        {
            if (ch != ' ')
                throw RPNException();
        }

        if (ch == '+' || ch == '-' || ch == '/' || ch == '*')
        {
            if (temp.size() < 2)
                throw RPNException();
            int right = temp.top(); temp.pop();
            int left = temp.top(); temp.pop();
            int result;
            switch (ch)
            {
                case '+':
                    result = left + right;
                    break;
                case '-':
                    result = left - right;
                    break;
                case '/':
                    if (right != 0)
                        result = left / right;
                    else
                        throw RPNException();
                break;
                case '*':
                    result = left * right;
                    break;
            }
            temp.push(result);
        }
        else if ('0' <= ch && ch <= '9')
            temp.push(ch - '0');

        flag = !flag;
        index++;
    }
    if (temp.size() != 1)
        throw RPNException();
    return temp.top();
}

const char*	RPN::RPNException::what() const throw() {
	return "RPN exception";
}
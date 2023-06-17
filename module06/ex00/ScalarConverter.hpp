#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <stdlib.h>

# define CHARTYPE 1;
# define INTTYPE 2;
# define FLOATTYPE 3;
# define DOUBLETYPE 4;

class ScalarConverter
{
private:
	int _type;
	std::string _value;
	char _char;
	std::string _char_err;
	int _int;
	std::string _int_err;
	float _float;
	std::string _float_err;
	double _double;
	std::string _double_err;

	void decideType();
	void printChar();
	void printInt();
	void printFloat();
	void printDouble();

	ScalarConverter();
	ScalarConverter(const ScalarConverter &ref);
	ScalarConverter& operator=(const ScalarConverter &ref);
	~ScalarConverter();

	static ScalarConverter instance;
	
public:
	static ScalarConverter* getInstance()
	{
		return (&instance);
	}
	void convert(std::string value);
};

#endif

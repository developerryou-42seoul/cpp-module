#include "ScalarConverter.hpp"

ScalarConverter ScalarConverter::instance = ScalarConverter();

ScalarConverter::ScalarConverter() : _type(0)
{}

ScalarConverter::ScalarConverter(const ScalarConverter &ref) : _type(ref._type)
{}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &ref)
{
	this->_type = ref._type;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{}

void ScalarConverter::decideType()
{

}

void ScalarConverter::printChar()
{
	std::cout<<"char : ";
	if (_char_err.empty())
		std::cout<<"'"<<_char<<"'"<<std::endl;
	else
		std::cout<<_char_err<<std::endl;
}

void ScalarConverter::printInt()
{
	std::cout<<"int : ";
	if (_int_err.empty())
		std::cout<<_int<<std::endl;
	else
		std::cout<<_int_err<<std::endl;
}

void ScalarConverter::printFloat()
{
	std::cout<<"float : ";
	if (_float_err.empty())
		std::cout<<_float<<"f"<<std::endl;
	else
		std::cout<<_float_err<<std::endl;
}

void ScalarConverter::printDouble()
{
	std::cout<<"double : ";
	if (_double_err.empty())
		std::cout<<_double<<std::endl;
	else
		std::cout<<_double_err<<std::endl;
}

void ScalarConverter::convert(std::string value)
{
	this->_value = value;

	if (_value.length() == 1 && !std::isdigit(_value[0]))
	{
		_type = CHARTYPE;
		_char = _value[0];
	}
	_double = strtod(this->_value.c_str(), NULL);
	if (_type == 0)
		_type = DOUBLETYPE;
	if (_double == 0 && !(_value[0] == '0' || ((_value[0] == '+' || _value[0] == '-') && _value[1] == '0')))
	{
		_double_err = "impossible";
		_float_err = "impossible";
		_int_err = "impossible";
		if (_type != 1)
			_char_err = "impossible";
	}
	else{
		_float = static_cast<float>(_double);

		_int = static_cast<int>(_double);
		if (_double < std::numeric_limits<int>::min() || std::numeric_limits<int>::max() < _double)
			_int_err = "impossible";

		if (_type != 1)
		{
			_char = static_cast<char>(_int);
		}
		if (!(32 <= _char && _char <= 126))
			_char_err = "Non displayable";
		if (_double < std::numeric_limits<char>::min() || std::numeric_limits<char>::max() < _double)
			_char_err = "impossible";

	}
	if (this->_value.find("nan", 0) == 0 || this->_value.find("+nan", 0) == 0 || this->_value.find("-nan", 0) == 0)
	{
		_double_err = "nanf";
		_float_err = "nan";
		_int_err = "impossible";
		_char_err = "impossible";
	}
	else if (this->_value.find("inf") == 0 || this->_value.find("+inf") == 0)
	{
		_double_err = "+inff";
		_float_err = "+inf";
		_int_err = "impossible";
		_char_err = "impossible";
	}
	else if (this->_value.find("-inf", 0) == 0)
	{
		_double_err = "-inff";
		_float_err = "-inf";
		_int_err = "impossible";
		_char_err = "impossible";
	}

	std::cout<<std::fixed;
    std::cout.precision(1);	
	printChar();
	printInt();
	printFloat();
	printDouble();
}

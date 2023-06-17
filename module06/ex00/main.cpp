#include <iostream>
#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout<<"One argument required"<<std::endl;
		return (1);
	}
	try
	{
		ScalarConverter *converter = ScalarConverter::getInstance();
		converter->convert(argv[1]);
	}
	catch(const std::exception &e) {
		std::cerr<<e.what()<<std::endl;
	}
}

#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char **argv)
{
	if (argc <= 1)
		std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else {
		for (int i=1;i<argc;i++) {
			std::string str = argv[i];
			for (unsigned long str_idx=0; str_idx<str.size(); str_idx++)
				str[str_idx] = std::toupper(str[str_idx]);
			std::cout<<str;
		}
	}
	std::cout<<std::endl;
}

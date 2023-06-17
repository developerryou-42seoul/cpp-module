#ifndef BASE_H
# define BASE_H
# include <iostream>
# include <string.h>
# include <unistd.h>

class Base
{
public:
	virtual	~Base() {
		std::cout<<"Base destructor called"<<std::endl;
	};
};

#endif

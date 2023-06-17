#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <time.h>


Base * generate(void)
{
	struct timespec specific_time;
    long millsec;
    clock_gettime(CLOCK_REALTIME, &specific_time);
    millsec = specific_time.tv_nsec;

	static int seed = 0;
	srand(millsec + seed);
	seed++;
	
	size_t	num = rand() % 3;
	Base	*base = NULL;

	try
	{
		if (num == 0)
			base = dynamic_cast<Base *>(new A);
		else if (num == 1)
			base = dynamic_cast<Base *>(new B);
		else if (num == 2)
			base = dynamic_cast<Base *>(new C);
		return (base);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (NULL);
	}
}

void	identify(Base* p)
{
	try
	{
		if (dynamic_cast<A *>(p))
			std::cout<<"A"<<std::endl;
		else if (dynamic_cast<B *>(p))
			std::cout<<"B"<<std::endl;
		else if (dynamic_cast<C *>(p))
			std::cout<<"C"<<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout<<"A"<<std::endl;
	}
	catch(const std::exception &e) { (void)e; }

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout<<"B"<<std::endl;
	}
	catch(const std::exception &e) { (void)e; }

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout<<"C"<<std::endl;
	}
	catch(const std::exception &e) { (void)e; }
}

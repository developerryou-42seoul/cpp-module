#include "Base.hpp"

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

int	main(void)
{
	Base * p1;
	Base * p2;

	p1 = generate();
	p2 = generate();

	std::cout << "pointer" << std::endl;
	identify(p1);
	identify(p2);

	std::cout << "reference" << std::endl;
	identify(*p1);
	identify(*p2);

	delete p1;
	delete p2;
	return (0);
}
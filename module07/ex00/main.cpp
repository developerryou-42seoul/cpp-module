#include <iostream>
#include "whatever.hpp"

int main(void)
{	
	{
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::cout<<std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
		std::cout<<std::endl;
	}
	{
		int a = 3;
		int b = 2;
		std::cout<<"a, b = "<<a<<", "<<b<<std::endl;
		::swap(a, b);
		std::cout<<"swaped"<<std::endl;
		std::cout<<"a, b = "<<a<<", "<<b<<std::endl;
		std::cout<<"min(a, b) = "<<::min(a, b)<<std::endl;
		std::cout<<"max(a, b) = "<<::max(a, b)<<std::endl;
		
		std::cout<<std::endl;

		std::string p1 = "tim";
		std::string p2 = "jeny";
		std::cout<<"p1, p2 = "<<p1<<", "<<p2<<std::endl;
		::swap(p1, p2);
		std::cout<<"swaped"<<std::endl;
		std::cout<<"p1, p2 = "<<p1<<", "<<p2<<std::endl;
		std::cout<<"min(p1, p2) = "<<::min(p1, p2)<<std::endl;
		std::cout<<"max(p1, p2) = "<<::max(p1, p2)<<std::endl;

		std::cout<<std::endl;

	}
	
	return 0;
}

#include <iostream>
#include "Point.hpp"
#include "Fixed.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main(void){
	{
		Point a(5, 5);
		Point b(2, 9);
		Point c(0, 5);
		Point p1(3, 7);
		Point p2(4, 7);

		std::cout << "Point a : " << a << std::endl;
		std::cout << "Point b : " << b << std::endl;
		std::cout << "Point c : " << c << std::endl;
		std::cout << "Point p1 : " << p1 << std::endl;
		std::cout << "Point p2 : " << p2 << std::endl;
		if (bsp(a, b, c, p1))
			std::cout << "p1 is in the triangle" << std::endl;
		else
			std::cout << "p1 is out of the triangle" << std::endl;
		if (bsp(a, b, c, p2))
			std::cout << "p2 is in the triangle" << std::endl;
		else
			std::cout << "p2 is out of the triangle" << std::endl;
	}
	{
		Point a(0, 0);
		Point b(5, 0);
		Point c(2, 3);
		Point p1(2, 2);
		Point p2(1, 1);

		std::cout << "Point a : " << a << std::endl;
		std::cout << "Point b : " << b << std::endl;
		std::cout << "Point c : " << c << std::endl;
		std::cout << "Point p1 : " << p1 << std::endl;
		std::cout << "Point p2 : " << p2 << std::endl;
		if (bsp(a, b, c, p1))
			std::cout << "p1 is in the triangle" << std::endl;
		else
			std::cout << "p1 is out of the triangle" << std::endl;
		if (bsp(a, b, c, p2))
			std::cout << "p2 is in the triangle" << std::endl;
		else
			std::cout << "p2 is out of the triangle" << std::endl;
	}
	return 0;
}
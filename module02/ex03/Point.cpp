#include "Point.hpp"

Point::Point(): _x(0), _y(0)
{
	//std::cout<<"Point Default Constructor called"<<std::endl;
}

Point::Point(const float x, const float y):_x(x), _y(y)
{
	//std::cout<<"Point Float Constuctor called"<<std::endl;
}

Point::Point(const Point &point)
{
	//std::cout<<"Point Copy Constructor called"<<std::endl;
	(*this) = point;
}
Point::~Point()
{
	//std::cout<<"Point Deconstructor called"<<std::endl;
}

Point &Point::operator=(const Point &point)
{
	//std::cout<<"Point Assignation operator called"<<std::endl;
	if (this != &point)
	{
		const_cast<Fixed&>(_x) = point.getX();
		const_cast<Fixed&>(_y) = point.getY();
	}
	return (*this);
}

const Fixed	&Point::getX(void) const
{
	return (this->_x);
}

const Fixed	&Point::getY(void) const
{
	return (this->_y);
}

std::ostream &operator<<(std::ostream &out, Point const point)
{
	out<<"x: "<< point.getX()<<" | y: "<< point.getY();
	return (out);
}
#include "Point.hpp"

float	ccw(Point const a, Point const b, Point const c)
{
	float ret = (a.getX()*b.getY() + b.getX()*c.getY() + c.getX()*a.getY())
		-	(b.getX()*a.getY() + c.getX()*b.getY() + a.getX()*c.getY());
	return ret;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float cp1 = ccw(a, b, point);
	float cp2 = ccw(b, c, point);
	float cp3 = ccw(c, a, point);
	//std::cout<<cp1<<" "<<cp2<<" "<<cp3<<std::endl;
	if (cp1 > 0 && cp2 > 0 && cp3 > 0)
		return (true);
	else if (cp1 < 0 && cp2 < 0 && cp3 < 0)
		return (true);
	return (false);
}

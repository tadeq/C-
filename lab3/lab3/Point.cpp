#include <iostream>
#include "Point.h"

using namespace std;

Point::Point(float xx, float yy)
{
	x = xx;
	y = yy;
}

ostream & operator<<(ostream & os, const Point p)
{
	os << p.x << " " << p.y;
	return os;
}

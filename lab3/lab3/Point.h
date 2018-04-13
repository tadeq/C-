#include <iostream>

using namespace std;

class Point
{
	float x;
	float y;
public:
	Point(float=0,float=0);
	friend ostream & operator<<(ostream &, const Point);
};

ostream & operator<<(ostream &, const Point);

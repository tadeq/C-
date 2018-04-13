#include <iostream>
#include "Point.h"

using namespace std;

class Polygon
{
	int size;
	int counter;
	Point* arr;
public:
	Polygon(int=3);
	Polygon(const Polygon &);
	Polygon(Polygon &&);
	Polygon & operator=(const Polygon &);
	Polygon & operator=(Polygon &&);
	int elements() const;
	void add(Point p);
	Point operator[](int n) const;
	~Polygon();
};


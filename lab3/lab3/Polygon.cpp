#include <iostream>
#include "Polygon.h"

using namespace std;

Polygon::Polygon(int n)
{
	size = n;
	arr = new Point[n];
	counter = 0;
}

Polygon::Polygon(const Polygon & polygon)
{
	counter = polygon.counter;
	size = polygon.size;
	arr = new Point[size];
	for (int i = 0; i < counter; i++) {
		arr[i] = polygon.arr[i];
	}
}

Polygon::Polygon(Polygon && polygon)
{
	counter = polygon.counter;
	size = polygon.size;
	arr = polygon.arr;
	polygon.arr = nullptr;
	polygon.counter = 0;
	polygon.size = 0;
}

Polygon & Polygon::operator=(const Polygon & polygon)
{
	counter = polygon.counter;
	size = polygon.size;
	delete[] arr;
	arr = new Point[size];
	for (int i = 0; i <= counter; i++) {
		arr[i] = polygon.arr[i];
	}
	return *this;
}

Polygon & Polygon::operator=(Polygon && polygon)
{
	counter = polygon.counter;
	size = polygon.size;
	arr = polygon.arr;
	polygon.arr = nullptr;
	polygon.counter = 0;
	polygon.size = 0;
	return *this;
}

int Polygon::elements() const
{
	return counter;
}

void Polygon::add(Point p)
{
	if (counter == size) {
		string exc = "No space left in points array";
		throw exc;
	}
	arr[counter++] = p;
}

Point Polygon::operator[](int n) const
{
	if (n<0 || n>=counter) {
		string exc = "No element with given index";
		throw exc;
	}
	else return arr[n];
}

Polygon::~Polygon()
{
	delete[] arr;
}

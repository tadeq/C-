#include <iostream>
#include <math.h>
#include "objects.h"

using namespace std;

Point3D::Point3D(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Point3D & Point3D::operator+(Vector3D w)
{
	this->x += w.x;
	this->y += w.y;
	this->z += w.z;
	return *this;
}

Point3D & Point3D::operator++()
{
	this->x++;
	this->y++;
	this->z++;
	return *this;
}

Point3D Point3D::operator++(int)
{
	Point3D newP = *this;
	this->x++;
	this->y++;
	this->z++;
	return newP;
}

ostream & operator<<(ostream & os, const Point3D p)
{
	os << "x: " << p.x << " y: " << p.y << " z: " << p.z;
	return os;
}

ostream & operator<<(ostream & os, const Vector3D w)
{
	os << "x: " << w.x << " y: " << w.y << " z: " << w.z;
	return os;
}

Vector3D operator*(Vector3D w,float f)
{
	w.x = w.x*f;
	w.y = w.y*f;
	w.z = w.z*f;
	return w;
}

Vector3D operator* (float f, Vector3D w)
{
	w.x = w.x*f;
	w.y = w.y*f;
	w.z = w.z*f;
	return w;
}

Vector3D::Vector3D(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3D & Vector3D::operator+=(Vector3D &w)
{
	this->x+=w.x;
	this->y+=w.y;
	this->z+=w.z;
	return *this;
}

Vector3D Vector3D::operator+ (Vector3D w) const
{
	return Vector3D(this->x + w.x, this->y + w.y, this->z + w.z);
}

Vector3D & Vector3D::operator-()
{
	this->x = -this->x;
	this->y = -this->y;
	this->z = -this->z;
	return *this;
}

bool Vector3D::operator>(const Vector3D w) const
{
	return (sqrt(this->x*this->x + this->y*this->y + this->z*this->z) > sqrt(w.x*w.x + w.y*w.y + w.z*w.z));
}

float Vector3D::operator[](int n) const
{
	switch (n) {
	case 0:
		return this->x;
	case 1:
		return this->y;
	case 2:
		return this->z;
	default:
		string exc = "Vector3D has only 3 elements!";
		throw exc;
	}
}

Vector3D::operator float() const
{
	return (sqrt(this->x*this->x + this->y*this->y + this->z*this->z));
}

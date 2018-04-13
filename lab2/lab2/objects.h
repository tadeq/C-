#include <iostream>

using namespace std;

class Vector3D {
	friend class Point3D;
private:
	float x, y, z;
public:
	Vector3D(float = 0, float = 0, float = 0);
	friend ostream & operator<<(ostream &, const Vector3D );
	Vector3D & operator+= (Vector3D &);
	Vector3D operator+ (Vector3D) const;
	friend Vector3D operator* (Vector3D, float);
	friend Vector3D operator* (float, Vector3D);
	Vector3D & operator- ();
	bool operator> (const Vector3D) const;
	float operator[] (int) const;
	operator float() const;
};

class Point3D {
	float x, y, z;
public:
	Point3D(float = 0, float = 0, float = 0);
	friend ostream & operator<<(ostream &, const Point3D);
	Point3D & operator+ (Vector3D);
	Point3D & operator++();
	Point3D operator++(int);
};

ostream & operator<<(ostream &, const Point3D);
ostream & operator<<(ostream &, const Vector3D);
Vector3D operator* (Vector3D, float);
Vector3D operator* (float, Vector3D);
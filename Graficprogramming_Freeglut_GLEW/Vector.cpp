#include "Vector.h"



Vector::Vector()
{
}

Vector::Vector(float x, float y, float z)
{
}

float Vector::dot(const Vector & v) const
{
	return 0.0f;
}

Vector Vector::cross(const Vector & v) const
{
	return Vector();
}

Vector Vector::operator+(const Vector & v) const
{
	return Vector();
}

Vector Vector::operator-(const Vector & v) const
{
	return Vector();
}

Vector & Vector::operator+=(const Vector & v)
{
	// TODO: hier Rückgabeanweisung eingeben
	this->x += v.x;
	this->y += v.y;
	this->z += v.z;
	return *this;
}

Vector Vector::operator*(float c) const
{
	return Vector();
}

Vector Vector::normalize()
{
	return Vector();
}

float Vector::length() const
{
	return 0.0f;
}

float Vector::lengthSquared() const
{
	return 0.0f;
}

Vector Vector::reflection(const Vector & normal) const
{
	return Vector();
}

bool Vector::triangleIntersection(const Vector & d, const Vector & a, const Vector & b, const Vector & c, const float & s)
{
	return false;
}
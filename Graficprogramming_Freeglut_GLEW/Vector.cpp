#include "Vector.h"
#include <math.h>


Vector::Vector()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

Vector::Vector(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

float Vector::dot(const Vector & v) const
{
	return this->x * v.x + this->y * v.y + this->z * v.z;
}

Vector Vector::cross(const Vector & v) const
{
	Vector erg;
	erg.x = this->y * v.z - this->z * v.y;
	erg.y = this->z * v.x - this->x * v.z;
	erg.z = this->x * v.y - this->y * v.x;
	return erg;
}

Vector Vector::operator+(const Vector & v) const
{
	Vector erg; 
	erg.x = this->x + v.x;
	erg.y = this->y + v.y;
	erg.z = this->z + v.z;
	return erg;
}

Vector Vector::operator-(const Vector & v) const
{
	Vector erg;
	erg.x = this->x - v.x;
	erg.y = this->y - v.y;
	erg.z = this->z - v.z;
	return erg;
}

Vector & Vector::operator+=(const Vector & v)
{
	this->x += v.x;
	this->y += v.y;
	this->z += v.z;
	return *this;
}

Vector Vector::operator*(float c) const
{
	Vector erg;
	erg.x = this->x * c;
	erg.y = this->y * c;
	erg.z = this->z * c;
	return erg;
}

// TODO: checking if this is working fine
Vector Vector::normalize()
{
	float _length = length();
	this->x = this->x / _length;
	this->y = this->y / _length;
	this->z = this->z / _length;
	return *this;
}

float Vector::length() const
{
	return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}

float Vector::lengthSquared() const
{
	return length() * length();
}


// TODO: methode reflection testen!
Vector Vector::reflection(const Vector& normal) const
{
	Vector erg;
	erg.x = 2 * normal.x * this->dot(normal) - this->x;
	erg.y = 2 * normal.y * this->dot(normal) - this->y;
	erg.z = 2 * normal.y * this->dot(normal) - this->y;
	return erg;
}

// TODO: funktion hinzufügen
bool Vector::triangleIntersection(const Vector & d, const Vector & a, const Vector & b, const Vector & c, const float & s)
{
	return false;
}
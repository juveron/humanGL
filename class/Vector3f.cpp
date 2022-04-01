#include "HumanGL.hpp"

Vector3f::Vector3f(void) : x(0), y(0), z(0)
{
}

Vector3f::Vector3f(float x_, float y_, float z_) : x(x_), y(y_), z(z_)
{
}

Vector3f::Vector3f(Vector3f const &c) : x(c.x), y(c.y), z(c.z)
{
}

Vector3f::~Vector3f(void)
{
}

float Vector3f::dotProduct(Vector3f const &vec) const
{
	return (this->x * vec.x + this->y * vec.y + this->z * vec.z);
}

float Vector3f::magnitude(void) const
{
	return (std::sqrt(this->x * this->x + this->y * this->y + this->z * this->z));
}

Vector3f Vector3f::crossProduct(Vector3f const &vec) const
{
	Vector3f cross;

	cross.x = this->y * vec.z - this->z * vec.y;
	cross.y = this->z * vec.x - this->x * vec.z;
	cross.z = this->x * vec.y - this->y * vec.x;

	return cross;
}

void Vector3f::normalize(void)
{
	float mag = this->magnitude();

	if (mag > 0)
		this->divide(mag);
}

void Vector3f::add(Vector3f const &vec)
{
	this->x += vec.x;
	this->y += vec.y;
	this->z += vec.z;
}

void Vector3f::substract(Vector3f const &vec)
{
	this->x -= vec.x;
	this->y -= vec.y;
	this->z -= vec.z;
}

void Vector3f::multiply(float const &num)
{
	this->x *= num;
	this->y *= num;
	this->z *= num;
}

void Vector3f::divide(float const &num)
{
	this->x /= num;
	this->y /= num;
	this->z /= num;
}

Vector3f &Vector3f::operator+=(Vector3f const &vec)
{
	this->add(vec);
	return *this;
}

Vector3f &Vector3f::operator-=(Vector3f const &vec)
{
	this->substract(vec);
	return *this;
}

Vector3f &Vector3f::operator*=(float const &num)
{
	this->multiply(num);
	return *this;
}

Vector3f &Vector3f::operator/=(float const &num)
{
	this->divide(num);
	return *this;
}

Vector3f &Vector3f::operator=(Vector3f const &rhs)
{
	this->x = rhs.x;
	this->y = rhs.y;
	this->z = rhs.z;
	return (*this);
}

Vector3f operator+(Vector3f const &lhs, Vector3f const &rhs)
{
	Vector3f tmp(lhs);
	tmp += rhs;
	return tmp;
}

Vector3f operator-(Vector3f const &lhs, Vector3f const &rhs)
{
	Vector3f tmp(lhs);
	tmp -= rhs;
	return tmp;
}

Vector3f operator*(Vector3f const &lhs, float const &rhs)
{
	Vector3f tmp(lhs);
	tmp *= rhs;
	return tmp;
}

Vector3f operator/(Vector3f const &lhs, float const &rhs)
{
	Vector3f tmp(lhs);
	tmp /= rhs;
	return tmp;
}

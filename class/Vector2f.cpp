#include "HumanGL.hpp"

Vector2f::Vector2f(void) : x(0), y(0)
{
}

Vector2f::Vector2f(float x_, float y_) : x(x_), y(y_)
{
}

Vector2f::Vector2f(Vector2f const &c) : x(c.x), y(c.y)
{
}

Vector2f::~Vector2f(void)
{
}

float Vector2f::dotProduct(Vector2f const &vec) const
{
	return (this->x * vec.x + this->y * vec.y);
}

float Vector2f::magnitude(void) const
{
	return (std::sqrt(this->x * this->x + this->y * this->y));
}

void Vector2f::normalize(void)
{
	float mag = this->magnitude();

	if (mag > 0)
		this->divide(mag);
}

void Vector2f::add(Vector2f const &vec)
{
	this->x += vec.x;
	this->y += vec.y;
}

void Vector2f::substract(Vector2f const &vec)
{
	this->x -= vec.x;
	this->y -= vec.y;
}

void Vector2f::multiply(float const &num)
{
	this->x *= num;
	this->y *= num;
}

void Vector2f::divide(float const &num)
{
	this->x /= num;
	this->y /= num;
}

Vector2f &Vector2f::operator+=(Vector2f const &vec)
{
	this->add(vec);
	return *this;
}

Vector2f &Vector2f::operator-=(Vector2f const &vec)
{
	this->substract(vec);
	return *this;
}

Vector2f &Vector2f::operator*=(float const &num)
{
	this->multiply(num);
	return *this;
}

Vector2f &Vector2f::operator/=(float const &num)
{
	this->divide(num);
	return *this;
}

Vector2f &Vector2f::operator=(Vector2f const &rhs)
{
	this->x = rhs.x;
	this->y = rhs.y;
	return (*this);
}

Vector2f operator+(Vector2f const &lhs, Vector2f const &rhs)
{
	Vector2f tmp(lhs);
	tmp += rhs;
	return tmp;
}

Vector2f operator-(Vector2f const &lhs, Vector2f const &rhs)
{
	Vector2f tmp(lhs);
	tmp -= rhs;
	return tmp;
}

Vector2f operator*(Vector2f const &lhs, float const &rhs)
{
	Vector2f tmp(lhs);
	tmp *= rhs;
	return tmp;
}

Vector2f operator/(Vector2f const &lhs, float const &rhs)
{
	Vector2f tmp(lhs);
	tmp /= rhs;
	return tmp;
}

#include "../hdr/HumanGL.hpp"

Vector4f::Vector4f(void) : x(0), y(0), z(0), w(0)
{
}

Vector4f::Vector4f(float x_, float y_, float z_, float w_) : x(x_), y(y_), z(z_), w(w_)
{
}

Vector4f::Vector4f(Vector3f const &vec, float w_) : x(vec.x), y(vec.y), z(vec.z), w(w_)
{
}

Vector4f::Vector4f(Vector4f const &c) : x(c.x), y(c.y), z(c.z), w(c.w)
{
}

Vector4f::~Vector4f(void)
{
}

float Vector4f::magnitude(void) const
{
	return (std::sqrt(this->x * this->x + this->y * this->y
		+ this->z * this->z + this->w * this->w));
}

void Vector4f::normalize(void)
{
	float mag = this->magnitude();

	if (mag > 0)
		this->divide(mag);
}

void Vector4f::add(Vector4f const &vec)
{
	this->x += vec.x;
	this->y += vec.y;
	this->z += vec.z;
	this->w += vec.w;
}

void Vector4f::substract(Vector4f const &vec)
{
	this->x -= vec.x;
	this->y -= vec.y;
	this->z -= vec.z;
	this->w -= vec.w;
}

void Vector4f::multiply(float const &num)
{
	this->x *= num;
	this->y *= num;
	this->z *= num;
	this->w *= num;
}

void Vector4f::multiply(Matrix4 const &mat)
{
	Vector4f tmp(*this);

	this->x = tmp.x * mat.matrix[0] + tmp.y * mat.matrix[4]
		+ tmp.y * mat.matrix[8] + tmp.z * mat.matrix[12];
	this->y = tmp.x * mat.matrix[1] + tmp.y * mat.matrix[5]
		+ tmp.y * mat.matrix[9] + tmp.z * mat.matrix[13];
	this->z = tmp.x * mat.matrix[2] + tmp.y * mat.matrix[6]
		+ tmp.y * mat.matrix[10] + tmp.z * mat.matrix[14];
	this->w = tmp.x * mat.matrix[3] + tmp.y * mat.matrix[7]
		+ tmp.y * mat.matrix[11] + tmp.z * mat.matrix[15];
}

void Vector4f::divide(float const &num)
{
	this->x /= num;
	this->y /= num;
	this->z /= num;
	this->w /= num;
}

Vector4f &Vector4f::operator+=(Vector4f const &vec)
{
	this->add(vec);
	return *this;
}

Vector4f &Vector4f::operator-=(Vector4f const &vec)
{
	this->substract(vec);
	return *this;
}

Vector4f &Vector4f::operator*=(float const &num)
{
	this->multiply(num);
	return *this;
}

Vector4f &Vector4f::operator/=(float const &num)
{
	this->divide(num);
	return *this;
}

Vector4f &Vector4f::operator=(Vector4f const &rhs)
{
	this->x = rhs.x;
	this->y = rhs.y;
	this->z = rhs.z;
	this->w = rhs.w;
	return (*this);
}

Vector4f operator+(Vector4f const &lhs, Vector4f const &rhs)
{
	Vector4f tmp(lhs);
	tmp += rhs;
	return tmp;
}

Vector4f operator-(Vector4f const &lhs, Vector4f const &rhs)
{
	Vector4f tmp(lhs);
	tmp -= rhs;
	return tmp;
}

Vector4f operator*(Vector4f const &lhs, float const &rhs)
{
	Vector4f tmp(lhs);
	tmp *= rhs;
	return tmp;
}

Vector4f operator/(Vector4f const &lhs, float const &rhs)
{
	Vector4f tmp(lhs);
	tmp /= rhs;
	return tmp;
}

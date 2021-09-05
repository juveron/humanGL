#ifndef VECTOR4F_HPP
#define VECTOR4F_HPP

#include "HumanGL.hpp"

class Matrix4;

// template <typename T>
class Vector4f {
public:
	Vector4f(void);
	Vector4f(float x_, float y_, float z_, float w_);
	Vector4f(Vector3f const &vec, float w_);
	Vector4f(Vector4f const &c);

	~Vector4f(void);

	float		x, y, z, w;
	float		magnitude(void) const;

	void		normalize(void);
	void		divide(float const &num);
	void		multiply(float const &num);
	void		multiply(Matrix4 const &mat);
	void		add(Vector4f const &vec);
	void		substract(Vector4f const &vec);

	Vector4f &operator+=(Vector4f const &f);
	Vector4f &operator-=(Vector4f const &f);
	Vector4f &operator*=(float const &f);
	Vector4f &operator/=(float const &f);
	Vector4f &operator=(Vector4f const &rhs);

	friend Vector4f operator+(Vector4f const &lhs, Vector4f const &rhs);
	friend Vector4f operator-(Vector4f const &lhs, Vector4f const &rhs);
	friend Vector4f operator*(Vector4f const &lhs, float const &rhs);
	friend Vector4f operator/(Vector4f const &lhs, float const &rhs);
};

#endif //HUMANGL_VECTOR_HPP

#ifndef VECTOR3F_HPP
#define VECTOR3F_HPP

#include "HumanGL.hpp"

class Vector3f {
public:
	Vector3f(void);
	Vector3f(float x_, float y_, float z_);
	Vector3f(Vector3f const &c);

	~Vector3f(void);

	float		x, y, z;
	float		dotProduct(Vector3f const &vec) const;
	float		magnitude(void) const;
	Vector3f	crossProduct(Vector3f const &vec) const;

	void		normalize(void);
	void		divide(float const &num);
	void		multiply(float const &num);
	void		add(Vector3f const &vec);
	void		substract(Vector3f const &vec);

	Vector3f &operator+=(Vector3f const &f);
	Vector3f &operator-=(Vector3f const &f);
	Vector3f &operator*=(float const &f);
	Vector3f &operator/=(float const &f);
	Vector3f &operator=(Vector3f const &rhs);

	friend Vector3f operator+(Vector3f const &lhs, Vector3f const &rhs);
	friend Vector3f operator-(Vector3f const &lhs, Vector3f const &rhs);
	friend Vector3f operator*(Vector3f const &lhs, float const &rhs);
	friend Vector3f operator/(Vector3f const &lhs, float const &rhs);
};

#endif //HUMANGL_VECTOR_HPP

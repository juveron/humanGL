#ifndef VECTOR2F_HPP
#define VECTOR2F_HPP

class Vector2f {
public:
	Vector2f(void);
	Vector2f(float x_, float y_);
	Vector2f(Vector2f const &c);

	~Vector2f(void);

	float		x, y;
	float		dotProduct(Vector2f const &vec) const;
	float		magnitude(void) const;

	void		normalize(void);
	void		divide(float const &num);
	void		multiply(float const &num);
	void		add(Vector2f const &vec);
	void		substract(Vector2f const &vec);

	Vector2f &operator+=(Vector2f const &f);
	Vector2f &operator-=(Vector2f const &f);
	Vector2f &operator*=(float const &f);
	Vector2f &operator/=(float const &f);
	Vector2f &operator=(Vector2f const &rhs);

	friend Vector2f operator+(Vector2f const &lhs, Vector2f const &rhs);
	friend Vector2f operator-(Vector2f const &lhs, Vector2f const &rhs);
	friend Vector2f operator*(Vector2f const &lhs, float const &rhs);
	friend Vector2f operator/(Vector2f const &lhs, float const &rhs);
};

#endif

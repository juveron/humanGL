//
// Created by juv on 12/07/2021.
//

#ifndef HUMANGL_MATRIX4_HPP
#define HUMANGL_MATRIX4_HPP

#include "../HumanGL.hpp"

class Matrix4 {
private:
	void rotateXAxis(float const angle = 0);
	void rotateYAxis(float const angle = 0);
	void rotateZAxis(float const angle = 0);

	static Matrix4 newXRotationMatrix(float const angle = 0);
	static Matrix4 newYRotationMatrix(float const angle = 0);
	static Matrix4 newZRotationMatrix(float const angle = 0);

public:
	float	matrix[16];

	Matrix4(void);
	Matrix4(Matrix4 const &c);
	~Matrix4(void);

	void	translate(float const x, float const y, float const z);
	void	translate(float const xyz);
	void	scale(float const x, float const y, float const z);
	void	scale(float const xyz);
	void	rotate(float const angle, e_axis const axis);

	void	multiply(Matrix4 const &mat);
	void	multiply(float const num);
	void	add(Matrix4 const &mat);
	void	substract(Matrix4 const &mat);

	Matrix4 &operator+=(Matrix4 const &rhs);
	Matrix4 &operator-=(Matrix4 const &rhs);
	Matrix4 &operator*=(Matrix4 const &rhs);
	Matrix4 &operator*=(float const &rhs);
	Matrix4 &operator=(Matrix4 const &rhs);

	friend Matrix4 operator+(Matrix4 const &lhs, Matrix4 const &rhs);
	friend Matrix4 operator-(Matrix4 const &lhs, Matrix4 const &rhs);
	friend Matrix4 operator*(Matrix4 const &lhs, Matrix4 const &rhs);
	friend Matrix4 operator*(Matrix4 const &lhs, float const &rhs);

	static Matrix4 newRotationMatrix(float const angle, e_axis const axis);
};


#endif //HUMANGL_MATRIX_HPP

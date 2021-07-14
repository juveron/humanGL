//
// Created by juv on 12/07/2021.
//

#ifndef HUMANGL_MATRIX4_HPP
#define HUMANGL_MATRIX4_HPP

#include "../HumanGL.hpp"

class Matrix4 {
public:
	float   matrix[16];
	Matrix4(void);
	~Matrix4(void);
	void	translate(float x, float y, float z);
	void	translate(float xyz);
	void	scale(float x, float y, float z);
	void	scale(float xyz);
	void	rotate(float angle, e_axis axis);

	void	multiply(Matrix4 mat);
	void	multiply(Vector3f vec);
	void	add(Matrix4 mat);
	void	sub(Matrix4 mat);
};


#endif //HUMANGL_MATRIX_HPP

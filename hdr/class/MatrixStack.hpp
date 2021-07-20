#ifndef MATRIXSTACK_HPP
#define MATRIXSTACK_HPP

#include "../HumanGL.hpp"

class MatrixStack
{
private:
	std::stack<Matrix4> _stack;

public:
	MatrixStack(void);
	MatrixStack(MatrixStack const &c) = delete;
	~MatrixStack(void);

	void pushMatrix(void);
	void pushMatrix(Matrix4 const &mat);
	void popMatrix(void);
	Matrix4 &topMatrix(void);

	MatrixStack &operator=(MatrixStack const &rhs) = delete;
};


#endif

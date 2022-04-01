#include "HumanGL.hpp"

MatrixStack::MatrixStack(void)
{
	this->_stack.push(Matrix4::newIdentityMatrix());
}

MatrixStack::~MatrixStack(void)
{
}

void MatrixStack::pushMatrix(void)
{
	this->_stack.push(this->_stack.top());
}

void MatrixStack::pushMatrix(Matrix4 const &mat)
{
	this->_stack.push(mat);
}

void MatrixStack::popMatrix(void)
{
	this->_stack.pop();
}

Matrix4 &MatrixStack::topMatrix(void)
{
	return this->_stack.top();
}

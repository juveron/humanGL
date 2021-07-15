#include "../hdr/HumanGL.hpp"

MatrixStack::MatrixStack(void)
{
}

MatrixStack::~MatrixStack(void)
{
}

void MatrixStack::pushMatrix(void)
{
	this->_stack.push(this->_stack.top());
}

void MatrixStack::popMatrix(void)
{
	this->_stack.pop();
}

Matrix4 MatrixStack::topMatrix(void)
{
	this->_stack.top();
}

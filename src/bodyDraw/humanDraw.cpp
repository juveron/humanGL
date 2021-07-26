//
// Created by juv on 15/07/2021.
//

#include "HumanGL.hpp"

void	drawLimb(Limb *limb, MatrixStack &matrixStack, Shader &shader)
{
	Matrix4		matrix4;
	std::vector<Limb *>::iterator iter = limb->children.begin();
	std::vector<Limb *>::iterator iterEnd = limb->children.end();

	Matrix4 top = matrixStack.topMatrix();

	matrixStack.pushMatrix(limb->currentMat);
	matrixStack.topMatrix().multiply(top);

	matrix4 = limb->scaleMat * matrixStack.topMatrix();

	shader.setMatrix("matrix", matrix4.matrix);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
	while (iter != iterEnd)
	{
		drawLimb(*iter, matrixStack, shader);
		iter++;
	}
	matrixStack.popMatrix();
}

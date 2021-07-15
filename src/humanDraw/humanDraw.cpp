//
// Created by juv on 15/07/2021.
//

#include "../../hdr/HumanGL.hpp"

void	drawLimb(Limb *limb, MatrixStack &matrixStack, Shader const &shader)
{
	Matrix4		matrix4;
	std::vector<Limb *>::iterator iter = limb->children.begin();
	std::vector<Limb *>::iterator iterEnd = limb->children.end();

	matrixStack.topMatrix().multiply(limb->currentMat);
	matrix4 = matrixStack.topMatrix() * limb->scaleMat;
	shader.setMatrix("matrix", matrix4);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
	while (inter != iterEnd)
	{
		matrixStack.pushMatrix();
		drawLimb(*iter, matrixStack, shader);
		matrixStack.popMatrix();
		iter++;
	}
}

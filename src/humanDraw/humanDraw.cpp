//
// Created by juv on 15/07/2021.
//

#include "../../hdr/HumanGL.hpp"

void	drawLimb(Limb *limb, MatrixStack &matrixStack, Shader &shader)
{
	Matrix4		matrix4;
	std::vector<Limb *>::iterator iter = limb->children.begin();
	std::vector<Limb *>::iterator iterEnd = limb->children.end();

	matrixStack.topMatrix().multiply(limb->currentMat);
	matrix4 = limb->scaleMat * matrixStack.topMatrix();
	// std::cout << "Top matrix:" << std::endl;
	// matrixStack.topMatrix().print();
	// std::cout << "===================" << std::endl;
	shader.setMatrix("matrix", matrix4.matrix);
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
	while (iter != iterEnd)
	{
		matrixStack.pushMatrix();
		// std::cout << "child" << std::endl;
		drawLimb(*iter, matrixStack, shader);
		matrixStack.popMatrix();
		iter++;
	}
}

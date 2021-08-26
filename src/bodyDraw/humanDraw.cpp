//
// Created by juv on 15/07/2021.
//

#include "HumanGL.hpp"

void	drawLimb(Limb *limb, int &limbIndex, int selectedLimb, MatrixStack &matrixStack, Shader &shader)
{
	Matrix4		matrix4;
	std::vector<Limb *>::iterator iter = limb->children.begin();
	std::vector<Limb *>::iterator iterEnd = limb->children.end();

	Matrix4 top = matrixStack.topMatrix();

	matrixStack.pushMatrix(limb->rotateMat * limb->translateMat);
	matrixStack.topMatrix().multiply(top);

	matrix4 = limb->scaleMat * matrixStack.topMatrix();

	shader.setMatrix("matrix", matrix4.matrix);
	if (limbIndex == selectedLimb)
		shader.setVector3f("color", 1.0f, 0.0f, 0.0f);
	else
		shader.setVector3f("color", 1.0f, 1.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glDrawArrays(GL_TRIANGLES, 0, 36);
	shader.setVector3f("color", 0.0f, 0.0f, 0.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glDrawArrays(GL_TRIANGLES, 0, 36);
	while (iter != iterEnd)
	{
		limbIndex++;
		drawLimb(*iter, limbIndex, selectedLimb, matrixStack, shader);
		iter++;
	}
	matrixStack.popMatrix();
}

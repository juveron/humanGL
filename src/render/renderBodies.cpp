#include "HumanGL.hpp"

void renderBodies(Shader &humanShader, Shader &doggoShader, Matrix4 &proj, Matrix4 &view,
				  s_indexBody &indexBody, ABody *bodies[], std::vector<Animation> animations[], float deltaTime, GLuint VAO)
{
	glViewport(0, 0, SCREEN_WIDTH_BODIES * ratio.x, SCREEN_HEIGHT * ratio.y);
	glScissor(0, 0, SCREEN_WIDTH_BODIES * ratio.x, SCREEN_HEIGHT * ratio.y);
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBindVertexArray(VAO);

	// // Draw human
	if (indexBody.drawBody & 1) {
		humanShader.use();
		humanShader.setMatrix("projMat", proj.matrix);
		humanShader.setMatrix("viewMat", view.matrix);
		bodies[0]->draw(humanShader);
		if (bodies[0]->isAnimated) {
			if (bodies[0]->animationIndex < animations[0].size()) {
				animations[0][bodies[0]->animationIndex].incrementProgress(deltaTime);
				bodies[0]->animate(animations[0][bodies[0]->animationIndex]);
			}
			else {
				bodies[0]->isAnimated = false;
			}
		}
	}

	// Draw doggo
	if ((indexBody.drawBody >> 1) & 1) {
		doggoShader.use();
		doggoShader.setMatrix("projMat", proj.matrix);
		doggoShader.setMatrix("viewMat", view.matrix);
		bodies[1]->draw(doggoShader);
		if (bodies[1]->isAnimated) {
			if (bodies[1]->animationIndex < animations[1].size()) {
				animations[1][bodies[1]->animationIndex].incrementProgress(deltaTime);
				bodies[1]->animate(animations[1][bodies[1]->animationIndex]);
			}
			else {
				bodies[1]->isAnimated = false;
			}
		}
	}
}

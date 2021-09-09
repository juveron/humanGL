#include "HumanGL.hpp"

void processInput(GLFWwindow *window, ABody *body, float deltaTime, s_indexBody &indexBody)
{
	static bool isLeftKeyPressed = 0;
	static bool isRightKeyPressed = 0;
	static bool isZKeyPressed = 0;
	static bool isNKeyPressed = 0;
	static bool isEqualKeyPressed = 0;

	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, 1);

	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
		if (!isLeftKeyPressed) {
			body->selectedLimb--;
			body->selectedLimb = body->selectedLimb < 0 ? body->limbs.size() - 1 : body->selectedLimb;
		}
		isLeftKeyPressed = 1;
	}
	else {
		isLeftKeyPressed = 0;
	}
	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
		if (!isRightKeyPressed) {
			body->selectedLimb = (body->selectedLimb + 1) % body->limbs.size();
		}
		isRightKeyPressed = 1;
	}
	else {
		isRightKeyPressed = 0;
	}

	// Rotation
	if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS)
		body->limbs[body->selectedLimb]->rotateLimb(45 * deltaTime, Y_AXIS);
	if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS)
		body->limbs[body->selectedLimb]->rotateLimb(-45 * deltaTime, Y_AXIS);
	if (glfwGetKey(window, GLFW_KEY_I) == GLFW_PRESS)
		body->limbs[body->selectedLimb]->rotateLimb(-45 * deltaTime, X_AXIS);
	if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS)
		body->limbs[body->selectedLimb]->rotateLimb(45 * deltaTime, X_AXIS);
	if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS)
		body->limbs[body->selectedLimb]->rotateLimb(45 * deltaTime, Z_AXIS);
	if (glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS)
		body->limbs[body->selectedLimb]->rotateLimb(-45 * deltaTime, Z_AXIS);

	// Translation
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		body->limbs[body->selectedLimb]->translateLimb(1.0f * deltaTime, 0.0f, 0.0f);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		body->limbs[body->selectedLimb]->translateLimb(-1.0f * deltaTime, 0.0f, 0.0f);
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		body->limbs[body->selectedLimb]->translateLimb(0.0f, 1.0f * deltaTime, 0.0f);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		body->limbs[body->selectedLimb]->translateLimb(0.0f, -1.0f * deltaTime, 0.0f);
	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
		body->limbs[body->selectedLimb]->translateLimb(0.0f, 0.0f, 1.0f * deltaTime);
	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
		body->limbs[body->selectedLimb]->translateLimb(0.0f, 0.0f, -1.0f * deltaTime);

	// Scale
	if (glfwGetKey(window, GLFW_KEY_H) == GLFW_PRESS) {
		body->limbs[body->selectedLimb]->scaleLimb(1.01f, 1.0f, 1.0f);
		body->position();
	}
	if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS) {
		body->limbs[body->selectedLimb]->scaleLimb(0.99f, 1.0f, 1.0f);
		body->position();
	}
	if (glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS) {
		body->limbs[body->selectedLimb]->scaleLimb(1.0f, 1.01f, 1.0f);
		body->position();
	}
	if (glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS) {
		body->limbs[body->selectedLimb]->scaleLimb(1.0f, 0.99f, 1.0f);
		body->position();
	}
	if (glfwGetKey(window, GLFW_KEY_Y) == GLFW_PRESS) {
		body->limbs[body->selectedLimb]->scaleLimb(1.0f, 1.0f, 1.01f);
		body->position();
	}
	if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS) {
		body->limbs[body->selectedLimb]->scaleLimb(1.0f, 1.0f, 0.99f);
		body->position();
	}

	// Reset body
	if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS) {
		body->resetBody();
	}

	// Reset limb
	if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS) {
		body->resetSelectedLimb();
	}

	// Switch body
	if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS) {
		if (!isZKeyPressed) {
			indexBody.drawBody = (indexBody.drawBody + 1) % 4;
			if (indexBody.drawBody == 0) indexBody.drawBody = 1;
			if (indexBody.drawBody <= 2) indexBody.modelIndex = (indexBody.modelIndex + 1) % 2;
		}
		isZKeyPressed = 1;
	}
	else isZKeyPressed = 0;

	// Switch body if the two are display
	if (glfwGetKey(window, GLFW_KEY_N) == GLFW_PRESS) {
		if (!isNKeyPressed)
			if (indexBody.drawBody == 3) indexBody.modelIndex = (indexBody.modelIndex + 1) % 2;
		isNKeyPressed = 1;
	}
	else isNKeyPressed = 0;

	// Loop anim
	if (glfwGetKey(window, GLFW_KEY_EQUAL) == GLFW_PRESS) {
		if (!isEqualKeyPressed)
			body->isAnimationLooping = !body->isAnimationLooping;
		isEqualKeyPressed = 1;
	}
	else isEqualKeyPressed = 0;

	// Print
	if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS)
		body->printToFile("./printedBody.txt");
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
		body->printToTerm();

	// Animation
	if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS) {
		body->isAnimated = true;
		body->animationIndex = 0;
	}
	if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS) {
		body->isAnimated = true;
		body->animationIndex = 1;
	}
	if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS) {
		body->isAnimated = true;
		body->animationIndex = 2;
	}
}

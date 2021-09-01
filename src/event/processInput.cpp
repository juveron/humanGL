#include "HumanGL.hpp"

void processInput(GLFWwindow *window, s_body &body, float deltaTime, s_animationData &stuff, s_indexBody &indexBody)
{
	static bool isLeftKeyPressed = 1;
	static bool isRightKeyPressed = 0;
	static bool isZKeyPressed = 1;
	static bool isNKeyPressed = 1;

	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, 1);

	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
		if (!isLeftKeyPressed) {
			body.selectedLimb--;
			body.selectedLimb = body.selectedLimb < 0 ? body.limbs.size() - 1 : body.selectedLimb;
		}
		isLeftKeyPressed = 1;
	}
	else {
		isLeftKeyPressed = 0;
	}
	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
		if (!isRightKeyPressed) {
			body.selectedLimb = (body.selectedLimb + 1) % body.limbs.size();
		}
		isRightKeyPressed = 1;
	}
	else {
		isRightKeyPressed = 0;
	}

	// Rotation
	if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS)
		body.limbs[body.selectedLimb]->rotateLimb(45 * deltaTime, Y_AXIS);
	if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS)
		body.limbs[body.selectedLimb]->rotateLimb(-45 * deltaTime, Y_AXIS);
	if (glfwGetKey(window, GLFW_KEY_I) == GLFW_PRESS)
		body.limbs[body.selectedLimb]->rotateLimb(-45 * deltaTime, X_AXIS);
	if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS)
		body.limbs[body.selectedLimb]->rotateLimb(45 * deltaTime, X_AXIS);
	if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS)
		body.limbs[body.selectedLimb]->rotateLimb(45 * deltaTime, Z_AXIS);
	if (glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS)
		body.limbs[body.selectedLimb]->rotateLimb(-45 * deltaTime, Z_AXIS);

	// Translation
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		body.limbs[body.selectedLimb]->translateLimb(1.0f * deltaTime, 0.0f, 0.0f);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		body.limbs[body.selectedLimb]->translateLimb(-1.0f * deltaTime, 0.0f, 0.0f);
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		body.limbs[body.selectedLimb]->translateLimb(0.0f, 1.0f * deltaTime, 0.0f);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		body.limbs[body.selectedLimb]->translateLimb(0.0f, -1.0f * deltaTime, 0.0f);
	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
		body.limbs[body.selectedLimb]->translateLimb(0.0f, 0.0f, 1.0f * deltaTime);
	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
		body.limbs[body.selectedLimb]->translateLimb(0.0f, 0.0f, -1.0f * deltaTime);

	// Scale
	if (glfwGetKey(window, GLFW_KEY_H) == GLFW_PRESS) {
		body.limbs[body.selectedLimb]->scaleLimb(1.01f, 1.0f, 1.0f);
		if (indexBody.bodyIndex == 0) positionHumanLimbs(body.limbs); else positionDoggoLimbs(body.limbs);
	}
	if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS) {
		body.limbs[body.selectedLimb]->scaleLimb(0.99f, 1.0f, 1.0f);
		if (indexBody.bodyIndex == 0) positionHumanLimbs(body.limbs); else positionDoggoLimbs(body.limbs);
	}
	if (glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS) {
		body.limbs[body.selectedLimb]->scaleLimb(1.0f, 1.01f, 1.0f);
		if (indexBody.bodyIndex == 0) positionHumanLimbs(body.limbs); else positionDoggoLimbs(body.limbs);
	}
	if (glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS) {
		body.limbs[body.selectedLimb]->scaleLimb(1.0f, 0.99f, 1.0f);
		if (indexBody.bodyIndex == 0) positionHumanLimbs(body.limbs); else positionDoggoLimbs(body.limbs);
	}
	if (glfwGetKey(window, GLFW_KEY_Y) == GLFW_PRESS) {
		body.limbs[body.selectedLimb]->scaleLimb(1.0f, 1.0f, 1.01f);
		if (indexBody.bodyIndex == 0) positionHumanLimbs(body.limbs); else positionDoggoLimbs(body.limbs);
	}
	if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS) {
		body.limbs[body.selectedLimb]->scaleLimb(1.0f, 1.0f, 0.99f);
		if (indexBody.bodyIndex == 0) positionHumanLimbs(body.limbs); else positionDoggoLimbs(body.limbs);
	}

	// Reset body
	if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS) {
		initBody(body, indexBody.modelIndex);
	}

	// Reset limb
	if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS) {
		initLimb(body, indexBody.modelIndex);
	}

	// Switch body
	if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS) {
		if (!isZKeyPressed) {
			indexBody.bodyIndex = (indexBody.bodyIndex + 1) % 2;
			indexBody.currentIndex = (indexBody.currentIndex + 1) % 3;
			if (indexBody.currentIndex == 2) indexBody.bodyIndex = 1;
		}
		isZKeyPressed = 1;
	} else isZKeyPressed = 0;

	// Switch body if the two are display
	if (glfwGetKey(window, GLFW_KEY_N) == GLFW_PRESS) {
		if (!isNKeyPressed)
			if (indexBody.currentIndex == 2) indexBody.modelIndex = (indexBody.modelIndex + 1) % 2;
		isNKeyPressed = 1;
	} else isNKeyPressed = 0;

	// Print
	if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS)
		printBodyToFile(body, "./printedHuman.txt");
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
		printBodyToTerm(body);

	// Animation
	if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS) {
		stuff.isAnimated = true;
		stuff.animationTime = 0;
		stuff.animationIndex = 1;
	}
}

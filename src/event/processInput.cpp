#include "HumanGL.hpp"

void processInput(GLFWwindow *window, s_body &body, float deltaTime)
{
	static bool isLeftKeyPressed = 1;
	static bool isRightKeyPressed = 0;

	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, 1);

	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
		if (!isLeftKeyPressed) {
			body.selectedLimb--;
			body.selectedLimb = body.selectedLimb < 0 ? body.limbs.size() : body.selectedLimb;
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
}

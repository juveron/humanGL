#include "../../hdr/HumanGL.hpp"

int main(void)
{
	GLFWwindow *window;

	if (!glfwInit()) {
		exit(EXIT_FAILURE);
		std::cout << "Error in glfwInit" << std::endl;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "HumanGL", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		std::cout << "Error while creating window" << std::endl;
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	try {
		Shader shader("./src/shadr/vertexShader.glsl", "./src/shader/fragmentShader.glsl");
	}
	catch (std::exception &e) {
		exit(EXIT_FAILURE);
	}

	while (!glfwWindowShouldClose(window))
	{
		processInput(window);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	return 0;
}

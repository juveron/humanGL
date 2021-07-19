#include "../../hdr/HumanGL.hpp"

int main(void)
{
	GLFWwindow *window;

	if (!glfwInit()) {
		exit(EXIT_FAILURE);
		std::cout << "Error in glfwInit" << std::endl;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
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
		Shader shader("./src/shader/vertexShader.glsl", "./src/shader/fragmentShader.glsl");


		float vertices[] = {
			0.5f,  0.5f, 0.0f,  // top right
			0.5f, -0.5f, 0.0f,  // bottom right
			-0.5f, -0.5f, 0.0f,  // bottom left
			-0.5f,  0.5f, 0.0f   // top left 
		};
		unsigned int indices[] = {  // note that we start from 0!
			0, 1, 3,  // first Triangle
		};
		unsigned int VBO, VAO, EBO;
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glGenBuffers(1, &EBO);
		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);

		// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		MatrixStack		matrixStack;
		Limb *base = new Limb();
		Limb *child = new Limb(base);
		Limb *child2 = new Limb(base);
		Limb *child3 = new Limb(child);
		Matrix4 proj = Matrix4::newProjectionMatrix(60.0f,
			static_cast<float>(SCREEN_HEIGHT) / static_cast<float>(SCREEN_WIDTH),
			0.1f, 100.0f);

		Matrix4 view = Matrix4::newLookAtMAt(Vector3f(0.0f, 0.0f, -3.0f),
			Vector3f(0.0f, 0.0f, 2.0f), Vector3f(0.0f, 1.0f, 0.0f));

		shader.use();
		shader.setMatrix("projMat", proj.matrix);
		shader.setMatrix("viewMat", view.matrix);
		child->scaleMat.scale(0.5);
		child->currentMat.translate(0.5f, 0.0f, 0.0f);
		child2->scaleMat.scale(0.5);
		child2->currentMat.translate(-0.5f, 0.0f, 0.0f);
		child3->scaleMat.scale(0.25);
		child3->currentMat.translate(0.25f, 0.0f, 0.0f);
		while (!glfwWindowShouldClose(window))
		{
			processInput(window);
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			base->currentMat.rotate(0.1f, Y_AXIS);
			child->currentMat.rotate(0.1f, X_AXIS);
			glBindVertexArray(VAO);
			matrixStack.pushMatrix();
			drawLimb(base, matrixStack, shader);
			matrixStack.popMatrix();
			glfwSwapBuffers(window);
			glfwPollEvents();
		}
	}
	catch (std::exception &e) {
		exit(EXIT_FAILURE);
	}
	return 0;
}

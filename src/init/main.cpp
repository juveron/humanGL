#include "HumanGL.hpp"

int main(void)
{
	GLFWwindow *window;

	if (!glfwInit()) ErrorHandler::setError("GLFW_INIT");

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "HumanGL", NULL, NULL);

	if (!window) ErrorHandler::setError("WINDOW");

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) ErrorHandler::setError("GLAD_LOAD");

	glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

	Shader shader("./src/shader/vertexShader.glsl", "./src/shader/fragmentShader.glsl");

		float vertices[] = {
			-0.5f,  0.0f,  0.5f,  // A 0
			 0.5f,  0.0f,  0.5f,  // B 1
			 0.5f, -1.0f,  0.5f,  // C 2
			-0.5f, -1.0f,  0.5f,  // D 3
			-0.5f,  0.0f, -0.5f,  // E 4
			 0.5f,  0.0f, -0.5f,  // F 5
			 0.5f, -1.0f, -0.5f,  // G 6
			-0.5f, -1.0f, -0.5f,  // H 7
		};
		unsigned int indices[] = {
			0, 2, 1, 0, 3, 2, // Front face
			4, 5, 6, 4, 6, 7, // Back face
			1, 2, 6, 1, 6, 5, // Right face
			0, 7, 3, 0, 4, 7, // Left face
			2, 3, 7, 2, 7, 6, // Bottom face
			0, 1, 5, 0, 5, 4  // Top face
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

		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		MatrixStack		matrixStack;

		Matrix4 proj = Matrix4::newProjectionMatrix(60.0f,
			static_cast<float>(SCREEN_HEIGHT) / static_cast<float>(SCREEN_WIDTH),
			0.1f, 100.0f);

		Matrix4 view = Matrix4::newLookAtMAt(Vector3f(0.0f, -2.0f, 5.0f),
			Vector3f(0.0f, -2.0f, 5.0f) - Vector3f(0.0f, 0.0f, -1.0f), Vector3f(0.0f, 1.0f, 0.0f));

		shader.use();
		shader.setMatrix("projMat", proj.matrix);
		shader.setMatrix("viewMat", view.matrix);
		s_body human = humanMaker();
		printBodyToTerm(human);
		printBodyToFile(human, "./human2.c");

		int zero;
		float deltaTime = 0;
		float lastFrame = 0;
		while (!glfwWindowShouldClose(window))
		{
			float currentFrame = glfwGetTime();
			deltaTime = currentFrame - lastFrame;
			lastFrame = currentFrame;
			processInput(window, human, deltaTime);
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			// human->currentMat.rotate(0.1f, Y_AXIS);
			glBindVertexArray(VAO);
			matrixStack.pushMatrix();
			zero = 0;
			drawLimb(human.limb, zero, human.selectedLimb, matrixStack, shader);
			matrixStack.popMatrix();
			glfwSwapBuffers(window);
			glfwPollEvents();
		}
	return 0;
}

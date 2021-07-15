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
		// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		// remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
		//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

		// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
		// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
		glBindVertexArray(0);

		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

		while (!glfwWindowShouldClose(window))
		{
			processInput(window);
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			shader.use();
			glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
		   //glDrawArrays(GL_TRIANGLES, 0, 6);
//		    shader.setMatrix("matrix", Matrix4::newIdentityMatrix().matrix);
//			glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
			Matrix4 matrix1;
//            matrix1.scale(0.5f);
//            matrix1.translate(0.05f, 0.0f, 0.0f);
			matrix1.rotate(90, Y_AXIS);
			shader.setMatrix("matrix", matrix1.matrix);
			glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
			glfwSwapBuffers(window);
			glfwPollEvents();
		}
	}
	catch (std::exception &e) {
		exit(EXIT_FAILURE);
	}
	return 0;
}

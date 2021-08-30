#include "HumanGL.hpp"

int main(void)
{
	GLFWwindow *window;

	if (!glfwInit()) ErrorHandler::setError("GLFW_INIT");


	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "HumanGL", NULL, NULL);

	if (!window) ErrorHandler::setError("WINDOW");

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) ErrorHandler::setError("GLAD_LOAD");

	glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

	Shader shader("./src/shader/vertexShader.glsl", "./src/shader/fragmentShader.glsl");

	// -0.5f,  0.0f,  0.5f,  // A 0
	//  0.5f,  0.0f,  0.5f,  // B 1
	//  0.5f, -1.0f,  0.5f,  // C 2
	// -0.5f, -1.0f,  0.5f,  // D 3
	// -0.5f, -1.0f,  0.5f,  // D 3
	// -0.5f,  0.0f, -0.5f,  // E 4
	//  0.5f,  0.0f, -0.5f,  // F 5
	//  0.5f, -1.0f, -0.5f,  // G 6
	// -0.5f, -1.0f, -0.5f,  // H 7

	// 	0, 2, 1, 0, 3, 2, // Front face
	// 	4, 5, 6, 4, 6, 7, // Back face
	// 	1, 2, 6, 1, 6, 5, // Right face
	// 	0, 7, 3, 0, 4, 7, // Left face
	// 	2, 3, 7, 2, 7, 6, // Bottom face
	// 	0, 1, 5, 0, 5, 4  // Top face
	float vertices[] = {
		// FRONT FACE
		-0.5f,  0.0f,  0.5f, 0.0f, 1.0f,
		 0.5f, -1.0f,  0.5f, 1.0f, 0.0f,
		 0.5f,  0.0f,  0.5f, 1.0f, 1.0f,
		-0.5f,  0.0f,  0.5f, 0.0f, 1.0f,
		-0.5f, -1.0f,  0.5f, 0.0f, 0.0f,
		 0.5f, -1.0f,  0.5f, 1.0f, 0.0f,

		 // BACK FACE
		-0.5f,  0.0f, -0.5f, 1.0f, 1.0f,
		 0.5f,  0.0f, -0.5f, 0.0f, 1.0f,
		 0.5f, -1.0f, -0.5f, 0.0f, 0.0f,
		-0.5f,  0.0f, -0.5f, 1.0f, 1.0f,
		 0.5f, -1.0f, -0.5f, 0.0f, 0.0f,
		-0.5f, -1.0f, -0.5f, 1.0f, 0.0f,

		// RIGHT FACE
		 0.5f,  0.0f,  0.5f, 0.0f, 1.0f,
		 0.5f, -1.0f,  0.5f, 0.0f, 0.0f,
		 0.5f, -1.0f, -0.5f, 1.0f, 0.0f,
		 0.5f,  0.0f,  0.5f, 0.0f, 1.0f,
		 0.5f, -1.0f, -0.5f, 1.0f, 0.0f,
		 0.5f,  0.0f, -0.5f, 1.0f, 1.0f,

		 // LEFT FACE
		 -0.5f,  0.0f,  0.5f, 1.0f, 1.0f,
		 -0.5f, -1.0f, -0.5f, 0.0f, 0.0f,
		 -0.5f, -1.0f,  0.5f, 1.0f, 0.0f,
		 -0.5f,  0.0f,  0.5f, 1.0f, 1.0f,
		 -0.5f,  0.0f, -0.5f, 0.0f, 1.0f,
		 -0.5f, -1.0f, -0.5f, 0.0f, 0.0f,

		 // BOTTOM FACE
		 0.5f, -1.0f,  0.5f, 1.0f, 1.0f, // C 2
		-0.5f, -1.0f,  0.5f, 0.0f, 1.0f, // D 3
		-0.5f, -1.0f, -0.5f, 0.0f, 0.0f, // H 7
		 0.5f, -1.0f,  0.5f, 1.0f, 1.0f, // C 2
		-0.5f, -1.0f, -0.5f, 0.0f, 0.0f, // H 7
		 0.5f, -1.0f, -0.5f, 1.0f, 0.0f, // G 6

		// TOP FACE
		-0.5f,  0.0f,  0.5f, 0.0f, 0.0f,
		 0.5f,  0.0f,  0.5f, 1.0f, 0.0f,
		 0.5f,  0.0f, -0.5f, 1.0f, 1.0f,
		-0.5f,  0.0f,  0.5f, 0.0f, 0.0f,
		 0.5f,  0.0f, -0.5f, 1.0f, 1.0f,
		-0.5f,  0.0f, -0.5f, 1.0f, 0.0f,
	};
	unsigned int VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// texture coord attribute
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	MatrixStack		matrixStack;

	Matrix4 proj = Matrix4::newProjectionMatrix(60.0f,
		static_cast<float>(SCREEN_HEIGHT) / static_cast<float>(SCREEN_WIDTH),
		0.1f, 100.0f);

	Matrix4 view = Matrix4::newLookAtMAt(Vector3f(0.0f, -2.0f, 5.0f),
		Vector3f(0.0f, -2.0f, 5.0f) - Vector3f(0.0f, 0.0f, -1.0f), Vector3f(0.0f, 1.0f, 0.0f));

	shader.use();
	shader.setMatrix("projMat", proj.matrix);
	shader.setMatrix("viewMat", view.matrix);

	std::vector<const char*> texturePaths = {
		"./ressources/Torso.png",
		"./ressources/Head.png",
		"./ressources/UpperArm.png",
		"./ressources/LowerArm.png",
		"./ressources/UpperArm.png",
		"./ressources/LowerArm.png",
		"./ressources/Thigh.png",
		"./ressources/Leg.png",
		"./ressources/Thigh.png",
		"./ressources/Leg.png",
	};

	unsigned int *textures = generateTextures(texturePaths);

	int current = 0;
	s_body body[2];
	body[0] = humanMaker();
	body[1] = doggoMaker();
	s_animationData animationData;

	animationData.isAnimated = false;
	animationData.animationTime = 0;

	int zero;
	float deltaTime = 0;
	float lastFrame = 0;
	while (!glfwWindowShouldClose(window)) {

		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		processInput(window, body[current], deltaTime, animationData, current);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glBindVertexArray(VAO);


		if (animationData.isAnimated) {
			animationData.animationTime += deltaTime;
			// animateBody(body[current], sittingDogAnim, sittingDogTime, animationData,current);
			animateBody(body[current], walkingAnim, walkingTime, animationData, current);
		}

		zero = 0;
		matrixStack.pushMatrix();
		drawLimb(body[current].limb, zero, body[current].selectedLimb, matrixStack, shader, textures);
		matrixStack.popMatrix();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	return 0;
}

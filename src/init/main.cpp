#include "HumanGL.hpp"

Vector2f ratio(1.0f, 1.0f);

int main(void)
{
	GLFWwindow *window;

	if (!glfwInit()) ErrorHandler::setError("GLFW_INIT");


	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	window = glfwCreateWindow(SCREEN_WIDTH * ratio.x, SCREEN_HEIGHT * ratio.y, "HumanGL", NULL, NULL);

	if (!window) ErrorHandler::setError("WINDOW");


	int width, height;
	glfwGetFramebufferSize(window, &width, &height);

#ifdef __APPLE__
	ratio.x = width / SCREEN_WIDTH;
	ratio.y = height / SCREEN_HEIGHT;
#endif
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) ErrorHandler::setError("GLAD_LOAD");


	Shader humanShader("./src/shader/humanVertexShader.glsl", "./src/shader/humanFragmentShader.glsl");
	Shader doggoShader("./src/shader/doggoVertexShader.glsl", "./src/shader/doggoFragmentShader.glsl");

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
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_SCISSOR_TEST);

	Matrix4 proj = Matrix4::newPerspectiveProjectionMatrix(60.0f,
		static_cast<float>(SCREEN_HEIGHT * ratio.y) / static_cast<float>(SCREEN_WIDTH_BODIES  * ratio.x),
		0.1f, 100.0f);

	Vector3f camPos(0.0f, -2.0, 5.0f);
	Vector3f camUp(0.0f, 1.0f, 0.0f);
	Vector3f camDir(0.0f, 0.0f, -1.0f);
	Matrix4 view = Matrix4::newLookAtMAt(camPos,
		camPos - camDir, camUp);


	std::vector<Animation> animations[2] = {
		{walkingHumanAnimation, jumpingHumanAnimation, flossingHumanAnimation},
		{jumpingDoggoAnimation, tailChasingDoggoAnimation, walkingOnFrontLegsAnimation}
	};

	std::vector<char const*> texturePaths = {
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

	Shader shaderText("./src/shader/textVertexShader.glsl", "./src/shader/textFragmentShader.glsl");
	Matrix4 projection = Matrix4::newOrthographicProjectionMatrix(0.0f, SCREEN_WIDTH_UI * ratio.x, 0.0f, SCREEN_HEIGHT * ratio.y);
	shaderText.use();
	shaderText.setMatrix("projection", projection.matrix);

	Font font("./Arimo-Regular.ttf", shaderText);
	s_indexBody indexBody;

	ABody *bodies[2]{
		new HumanBody(),
		new DoggoBody()
	};

	bodies[0]->setTextures(generateTextures(texturePaths));

	int zero;
	float deltaTime = 0;
	float lastFrame = 0;
	while (!glfwWindowShouldClose(window)) {

		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		processInput(window, bodies[indexBody.modelIndex], deltaTime, indexBody);
		renderBodies(humanShader, doggoShader, proj, view, indexBody, bodies, animations, deltaTime, VAO);
		renderUI(font, indexBody, bodies[indexBody.modelIndex]);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	return 0;
}

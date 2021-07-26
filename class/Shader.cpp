#include "../hdr/HumanGL.hpp"

Shader::Shader(char const *vShaderPath, char const *fShaderPath)
{
	std::ifstream vShaderFile;
	std::ifstream fShaderFile;

	vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	std::string vShaderCode;
	std::string fShaderCode;
	try {
		std::stringstream vShaderStream;
		std::stringstream fShaderStream;
		vShaderFile.open(vShaderPath);
		fShaderFile.open(fShaderPath);

		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();

		vShaderCode = vShaderStream.str();
		fShaderCode = fShaderStream.str();

		fShaderFile.close();
		vShaderFile.close();
	}
	catch (std::ifstream::failure &e) {
		ErrorHandler::setError("SHADER_CONSTRUCT", e.what());
	}

	char const *vShaderChar = vShaderCode.c_str();
	char const *fShaderChar = fShaderCode.c_str();

	unsigned int vertexShader, fragmentShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vertexShader, 1, &vShaderChar, NULL);
	glShaderSource(fragmentShader, 1, &fShaderChar, NULL);
	glCompileShader(vertexShader);
	this->checkCompileError(vertexShader, "VERTEX");
	glCompileShader(fragmentShader);
	this->checkCompileError(fragmentShader, "FRAGMENT");

	this->_id = glCreateProgram();
	glAttachShader(this->_id, vertexShader);
	glAttachShader(this->_id, fragmentShader);
	glLinkProgram(this->_id);
	this->checkCompileError(this->_id, "PROGRAM");
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

Shader::~Shader(void)
{
}

void Shader::checkCompileError(GLuint shader, std::string type)
{
	int success;
	char infoLog[512];

	if (type != "PROGRAM")
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shader, 512, NULL, infoLog);
			std::cerr << "ERROR: SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n-------------------------------------------------------" << std::endl;
		}
	}
	else {
		glGetProgramiv(shader, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "ERROR: PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n-------------------------------------------------------" << std::endl;
		}
	}
}

void Shader::use(void)
{
	glUseProgram(this->_id);
}

void Shader::setMatrix(char const *name, float mat4[16])
{
	glUniformMatrix4fv(glGetUniformLocation(this->_id, name), 1, GL_FALSE, mat4);
}

void Shader::setVector3f(char const *name, float red, float green, float blue)
{
	glUniform3f(glGetUniformLocation(this->_id, name), red, green, blue);
}

void Shader::setBool(char const *name, bool value)
{
	glUniform1i(glGetUniformLocation(this->_id, name), static_cast<int>(value));
}

void Shader::setInt(char const *name, int value)
{
	glUniform1i(glGetUniformLocation(this->_id, name), value);
}

void Shader::setFloat(char const *name, float value)
{
	glUniform1f(glGetUniformLocation(this->_id, name), value);
}

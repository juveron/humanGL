#include "../../hdr/HumanGL.hpp"

Shader::Shader(char const *vertexShaderPath, char const *fragmentShaderPath)
{
	std::ifstream file(vertexShaderPath);
	std::ifstream file(fragmentShaderPath);
}

Shader::~Shader(void)
{
}

void Shader::use(void)
{
	glUseProgram(this->id);
}

void Shader::setBool(char const *name, bool value)
{
	glUniform1i(glGetUniformLocation(this->id, name), static_cast<int>(value));
}

void Shader::setInt(char const *name, int value)
{
	glUniform1i(glGetUniformLocation(this->id, name), value);
}

void Shader::setFloat(char const *name, float value)
{
	glUniform1f(glGetUniformLocation(this->id, name), value);
}

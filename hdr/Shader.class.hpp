#ifndef SHADER_CLASS_HPP
#define SHADER_CLASS_HPP

#include "./HumanGL.hpp"

class Shader
{
private:
	unsigned int id;

public:
	Shader(void) = delete;
	Shader(char const *vertexShaderPath, char const *fragmentShaderPath);
	Shader(Shader const &c) = delete;
	~Shader(void);

	void use(void);

	void setBool(char const *name, bool value);
	void setInt(char const *name, int value);
	void setFloat(char const *name, float value);
};

#endif

#ifndef SHADER_HPP
#define SHADER_HPP

#include "HumanGL.hpp"

class Shader
{
private:
	unsigned int _id;
	void checkCompileError(GLuint shader, std::string type);

public:
	Shader(void) = delete;
	Shader(char const *vertexShaderPath, char const *fragmentShaderPath);
	Shader(Shader const &c);
	~Shader(void);

	void use(void) const;
	unsigned int getId(void) const;

	void setMatrix(char const *name, float mat4[16]);
	void setVector3f(char const *name, float red, float green, float blue);
	void setBool(char const *name, bool value);
	void setInt(char const *name, int value);
	void setFloat(char const *name, float value);
};

#endif

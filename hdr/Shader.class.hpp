#ifndef SHADER_CLASS_HPP
#define SHADER_CLASS_HPP

#include "./HumanGL.hpp"

class Shader
{
private:
	unsigned int Id;
public:
	Shader(void) = delete;
	Shader(std::string const vertexShaderPath, std::string const fragmentShaderPath);
	Shader(Shader const &c) = delete;
	~Shader(void);

	void use(void);

	void setBool(std::string const name, bool value);
	void setInt(std::string const name, int value);
	void setFloat(std::string const name, float value);
};


#endif

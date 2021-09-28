#ifndef TEXTURE_HPP
#define TEXTURE_HPP


#include "HumanGL.hpp"

class Texture
{
private:
	GLuint _id;
	GLenum _target;

public:
	Texture(GLenum const target, GLint const internalFormat, GLint const format, GLenum const type, s_textureInfo const &info);
	Texture(GLuint id_, GLenum target_);
	Texture(Texture const &c) = delete;
	~Texture(void);

	void setTextureParameteri(GLenum const pname, GLint const param);

	void bind(void) const;
	GLuint getId(void) const;
	GLenum getTarget(void) const;

	Texture &operator=(Texture const &rhs) = delete;

	// static s_textureInfo loadTexture(char const *filename);
};


#endif 

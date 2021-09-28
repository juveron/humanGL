#include "HumanGL.hpp"

Texture::Texture(GLenum const target, GLint const internalFormat, GLint const format, GLenum const type, s_textureInfo const &info) : _target(target)
{
	glGenTextures(1, &(this->_id));
	glBindTexture(target, this->_id);
	glTexImage2D(target, 0, internalFormat, info.width, info.height, 0, format, type, info.data);
	glGenerateMipmap(target);
}

Texture::Texture(GLuint id_, GLenum target_) : _id(id_), _target(target_)
{
}

Texture::~Texture(void)
{
}

void Texture::setTextureParameteri(GLenum const pname, GLint const param)
{
	glTexParameteri(this->_target, pname, param);
}

void Texture::bind(void) const
{
	glBindTexture(this->_target, this->_id);
}

GLuint Texture::getId(void) const
{
	return this->_id;
}

GLenum Texture::getTarget(void) const
{
	return this->_target;
}

// s_textureInfo Texture::loadTexture(char const *filename)
// {
// 	s_textureInfo textureData;

// 	textureData.data = stbi_load(filename, &textureData.width,
// 		&textureData.height, &textureData.nbrChannels, 0);
// 	if (!textureData.data)
// 		ErrorHandler::setError("TEXTURE_LOAD");
// 	return textureData;
// }

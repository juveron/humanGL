#include "HumanGL.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "./stb_image.h"


unsigned int generateTexture(void)
{
	int width, height, nbrChannels;
	unsigned int texture;

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	unsigned char *data = stbi_load("./src/texture/container.jpg", &width, &height, &nbrChannels, 0);

	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else {
		ErrorHandler::setError("TEXTURE_LOAD");
	}

	stbi_image_free(data);
	return texture;
}

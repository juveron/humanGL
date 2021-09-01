#include "HumanGL.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "./stb_image.h"

static s_textureData loadTexture(const char *fileName)
{
	s_textureData textureData;

	textureData.data = stbi_load(fileName, &textureData.width,
		&textureData.height, &textureData.nbrChannels, 0);
	if (!textureData.data)
		ErrorHandler::setError("TEXTURE_LOAD");
	return textureData;
}

unsigned int *generateTextures(std::vector<const char *> texturePaths)
{
	unsigned int *textures = new unsigned int[texturePaths.size()];
	size_t i = 0;
	size_t texNum = texturePaths.size();

	glGenTextures(texturePaths.size(), textures);
	std::vector<s_textureData> texturesData;

	while (i < texNum)
	{
		s_textureData textureData = loadTexture(texturePaths[i]);
		glBindTexture(GL_TEXTURE_2D, textures[i]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, textureData.width, textureData.height,
			0, GL_RGB, GL_UNSIGNED_BYTE, textureData.data);
		glGenerateMipmap(GL_TEXTURE_2D);
		stbi_image_free(textureData.data);
		i++;
	}

	return textures;
}

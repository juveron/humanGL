#include "HumanGL.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

static s_textureInfo loadTexture(char const *fileName)
{
	s_textureInfo textureData;

	textureData.data = stbi_load(fileName, &textureData.width,
		&textureData.height, &textureData.nbrChannels, 0);
	if (!textureData.data)
		ErrorHandler::setError("TEXTURE_LOAD");
	return textureData;
}

unsigned int *generateTextures(std::vector<char const *> texturePaths)
{
	unsigned int *textures = new unsigned int[texturePaths.size()];
	size_t i = 0;
	size_t texNum = texturePaths.size();

	glGenTextures(texturePaths.size(), textures);
	std::vector<s_textureInfo> texturesData;

	while (i < texNum)
	{
		s_textureInfo textureData = loadTexture(texturePaths[i]);
		Texture tex(GL_TEXTURE_2D, GL_RGB, GL_RGB, GL_UNSIGNED_BYTE, textureData);
		tex.bind();
		tex.setTextureParameteri(GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		tex.setTextureParameteri(GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		stbi_image_free(textureData.data);
		textures[i] = tex.getId();
		i++;
	}

	return textures;
}

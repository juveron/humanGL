#ifndef FONT_HPP
#define FONT_HPP

#include "HumanGL.hpp"

class Font
{
private:
	std::map<GLchar, Character> _characters;
	Shader _shader;
	GLuint _vao, _vbo;

	void loadCharacters(FT_Face const &face);

public:
	Font(std::string const &filePath, Shader const &c);
	Font(Font const &c);
	~Font(void);

	std::map<GLchar, Character> getCharacters(void) const;
	Shader getShader(void) const;
	GLuint getVAO(void) const;
	GLuint getVBO(void) const;

	void renderText(std::string text, unsigned int alignMode, float y, float scale, Vector3f color);
	void renderUnderlinedText(std::string text, unsigned int alignMode, float y, float scale, Vector3f color);

	static float getFirstPosition(unsigned int alignMode, float textWidth);

	Font &operator=(Font const &rhs);

};

#endif

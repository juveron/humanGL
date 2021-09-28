#include "HumanGL.hpp"

Font::Font(std::string const &filePath, Shader const &s) : _shader(s)
{
	FT_Library lib;
	if (FT_Init_FreeType(&lib))
		ErrorHandler::setError("FREETYPE_LIB_INIT");

	FT_Face face;
	if (FT_New_Face(lib, filePath.c_str(), 0, &face))
		ErrorHandler::setError("FREETYPE_FACE_CREATION");

	FT_Set_Pixel_Sizes(face, 0, 48);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	this->loadCharacters(face);

	FT_Done_Face(face);
	FT_Done_FreeType(lib);


	glGenVertexArrays(1, &this->_vao);
	glGenBuffers(1, &this->_vbo);
	glBindVertexArray(this->_vao);
	glBindBuffer(GL_ARRAY_BUFFER, this->_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6 * 4, NULL, GL_DYNAMIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

Font::Font(Font const &c) : _characters(c.getCharacters()), _shader(c.getShader()), _vao(c.getVAO()), _vbo(c._vbo)
{
}

Font::~Font(void)
{
}

void Font::loadCharacters(FT_Face const &face)
{
	for (unsigned char c = 0; c < 128; c++) {
		if (FT_Load_Char(face, c, FT_LOAD_RENDER))
			ErrorHandler::setError("FREETYPE_LOAD_CHAR");

		s_textureInfo info = {
			face->glyph->bitmap.buffer,
			static_cast<int>(face->glyph->bitmap.width),
			static_cast<int>(face->glyph->bitmap.rows),
			1
		};

		Texture tex(GL_TEXTURE_2D, GL_RED, GL_RED, GL_UNSIGNED_BYTE, info);
		tex.setTextureParameteri(GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		tex.setTextureParameteri(GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		tex.setTextureParameteri(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		tex.setTextureParameteri(GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		Character character = {
			tex.getId(),
			Vector2f(info.width, info.height),
			Vector2f(face->glyph->bitmap_left, face->glyph->bitmap_top),
			static_cast<unsigned int>(face->glyph->advance.x)
		};

		this->_characters.insert(std::pair<char, Character>(c, character));
	}
}

std::map<GLchar, Character> Font::getCharacters(void) const
{
	return this->_characters;
}

Shader Font::getShader(void) const
{
	return this->_shader;
}

GLuint Font::getVAO(void) const
{
	return this->_vao;
}

GLuint Font::getVBO(void) const
{
	return this->_vbo;
}

void Font::renderText(std::string text, float x, float y, float scale, Vector3f color)
{
	this->_shader.use();
	this->_shader.setVector3f("textColor", color.x, color.y, color.z);
	glActiveTexture(GL_TEXTURE0);
	glBindVertexArray(this->_vao);

	// iterate through all characters
	glBindBuffer(GL_ARRAY_BUFFER, this->_vbo);
	std::string::const_iterator c;
	for (c = text.begin(); c != text.end(); c++)
	{
		Character ch = this->_characters[*c];

		Texture tex(ch.textureId, GL_TEXTURE_2D);

		float xpos = x + ch.bearing.x * scale;
		float ypos = y - (ch.size.y - ch.bearing.y) * scale;

		float w = ch.size.x * scale;
		float h = ch.size.y * scale;
		// update this->_vbo for each character
		float vertices[6][4] = {
			{ xpos,     ypos + h,   0.0f, 0.0f },
			{ xpos,     ypos,       0.0f, 1.0f },
			{ xpos + w, ypos,       1.0f, 1.0f },

			{ xpos,     ypos + h,   0.0f, 0.0f },
			{ xpos + w, ypos,       1.0f, 1.0f },
			{ xpos + w, ypos + h,   1.0f, 0.0f }
		};
		tex.bind();

		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices); // be sure to use glBufferSubData and not glBufferData
		glDrawArrays(GL_TRIANGLES, 0, 6);
		// now advance cursors for next glyph (note that advance is number of 1/64 pixels)
		x += (ch.advance >> 6) * scale; // bitshift by 6 to get value in pixels (2^6 = 64 (divide amount of 1/64th pixels by 64 to get amount of pixels))
	}
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Font::renderUnderlinedText(std::string text, float x, float y, float scale, Vector3f color)
{
	this->_shader.use();
	this->_shader.setVector3f("textColor", color.x, color.y, color.z);
	glActiveTexture(GL_TEXTURE0);
	glBindVertexArray(this->_vao);

	float initialX = x;

	// iterate through all characters
	glBindBuffer(GL_ARRAY_BUFFER, this->_vbo);
	std::string::const_iterator c;
	for (c = text.begin(); c != text.end(); c++)
	{
		Character ch = this->_characters[*c];

		Texture tex(ch.textureId, GL_TEXTURE_2D);
		float xpos = x + ch.bearing.x * scale;
		float ypos = y - (ch.size.y - ch.bearing.y) * scale;

		float w = ch.size.x * scale;
		float h = ch.size.y * scale;
		// update this->_vbo for each character
		float vertices[6][4] = {
			{ xpos,     ypos + h,   0.0f, 0.0f },
			{ xpos,     ypos,       0.0f, 1.0f },
			{ xpos + w, ypos,       1.0f, 1.0f },

			{ xpos,     ypos + h,   0.0f, 0.0f },
			{ xpos + w, ypos,       1.0f, 1.0f },
			{ xpos + w, ypos + h,   1.0f, 0.0f }
		};
		tex.bind();

		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices); // be sure to use glBufferSubData and not glBufferData

		glDrawArrays(GL_TRIANGLES, 0, 6);
		// now advance cursors for next glyph (note that advance is number of 1/64 pixels)
		x += (ch.advance >> 6) * scale; // bitshift by 6 to get value in pixels (2^6 = 64 (divide amount of 1/64th pixels by 64 to get amount of pixels))
	}

	Texture tex(46, GL_TEXTURE_2D);

	float vertices[6][4] = {
		{ initialX, y - 3, 0.0f, 0.0f },
		{ initialX, y - 5, 0.0f, 1.0f },
		{ x,        y - 5, 1.0f, 1.0f },

		{ initialX, y - 3, 0.0f, 0.0f },
		{ x,        y - 5, 1.0f, 1.0f },
		{ x,        y - 3, 1.0f, 0.0f }
	};
	tex.bind();
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices); // be sure to use glBufferSubData and not glBufferData

	glDrawArrays(GL_TRIANGLES, 0, 6);

	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
}

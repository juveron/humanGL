#include "HumanGL.hpp"

std::map<std::string, std::string> ErrorHandler::_errorDictionary{
		{ "GLFW_INIT" , "Error with glfwInit" },
		{ "WINDOW", "Error while creating window" },
		{ "GLAD_LOAD", "Error with gladLoadGLLoader" },
		{ "SHADER_CONSTRUCT", "Unable to open /read/close file for Shader" },
		{ "SHADER_COMPILATION", "Error occurred during the compilation of the Shader" },
		{ "TEXTURE_LOAD", "Couldn't load given texture" },
		{ "PRINT_FILE", "Unable to open /read/close file for printing purposes" },
		{ "FREETYPE_LIB_INIT", "Error in FT_INIT_FreeType" },
		{ "FREETYPE_FACE_CREATION", "Error while creating a FT_Face" },
		{ "FREETYPE_LOAD_CHAR", "Failed to load glyph for a certain character" }
};

void ErrorHandler::setError(const std::string &errorKey)
{
	glfwTerminate();
	std::cout << ErrorHandler::_errorDictionary[errorKey] << std::endl;
	exit(EXIT_FAILURE);
}

void ErrorHandler::setError(const std::string &errorKey, const char* errorMessage)
{
	glfwTerminate();
	std::cout << ErrorHandler::_errorDictionary[errorKey] << ":\n" << errorMessage << std::flush;
	exit(EXIT_FAILURE);
}

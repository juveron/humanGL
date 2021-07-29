//
// Created by juv on 20/07/2021.
//

#include "../hdr/HumanGL.hpp"

std::map<std::string, std::string> ErrorHandler::_errorDictionary {
		{ "GLFW_INIT" , "Error with glfwInit" },
		{ "WINDOW", "Error while creating window" },
		{ "GLAD_LOAD", "Error with gladLoadGLLoader" },
		{ "SHADER_CONSTRUCT", "Unable to open /read/close file for Shader"}
};

void ErrorHandler::setError(const std::string &errorKey) {
	glfwTerminate();
	std::cout << ErrorHandler::_errorDictionary[errorKey] << std::endl;
	exit(EXIT_FAILURE);
}

void ErrorHandler::setError(const std::string &errorKey, const char* errorMessage) {
	glfwTerminate();
	std::cout << ErrorHandler::_errorDictionary[errorKey] << ":\n" << errorMessage << std::endl;
	exit(EXIT_FAILURE);
}

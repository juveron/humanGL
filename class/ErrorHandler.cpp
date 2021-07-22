//
// Created by juv on 20/07/2021.
//

#include "../hdr/HumanGL.hpp"

std::map<std::string, std::string> ErrorHandler::_errorDictionary {
		{ "GLFW_INIT" , "Error with glfwInit" },
		{ "TEST", "CA A REUSSI LALALA" },
		{ "", "" }
};

void ErrorHandler::setError(const std::string &errorKey) {
	glfwTerminate();
	std::cout << ErrorHandler::_errorDictionary[errorKey] << std::endl;
	exit(EXIT_FAILURE);
}
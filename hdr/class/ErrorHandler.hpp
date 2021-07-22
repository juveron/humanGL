//
// Created by juv on 20/07/2021.
//

#ifndef HUMANGL_ERRORHANDLER_HPP
#define HUMANGL_ERRORHANDLER_HPP

#include "../HumanGL.hpp"

class ErrorHandler {
private:
	~ErrorHandler(void);
	static std::map<std::string, std::string> _errorDictionary;
public:
	ErrorHandler(void) = delete;
	ErrorHandler(ErrorHandler const &c) = delete;

	static void	setError(const std::string &errorKey);

	ErrorHandler &operator=(ErrorHandler const &rhs) = delete;
};


#endif //HUMANGL_ERRORHANDLER_HPP

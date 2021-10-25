#ifndef ERRORHANDLER_HPP
#define ERRORHANDLER_HPP

#include "HumanGL.hpp"

class ErrorHandler {
private:
	~ErrorHandler(void);
	static std::map<std::string, std::string> _errorDictionary;
public:
	ErrorHandler(void) = delete;
	ErrorHandler(ErrorHandler const &c) = delete;

	static void	setError(const std::string &errorKey);
	static void setError(const std::string &errorKey, const char* errorMessage);

	ErrorHandler &operator=(ErrorHandler const &rhs) = delete;
};


#endif

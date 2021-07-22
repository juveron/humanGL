#ifndef PROTO_HPP
#define PROTO_HPP


#include "./HumanGL.hpp"

// input
void processInput(GLFWwindow *window);

// Draw human
void	drawLimb(Limb *limb, MatrixStack &matrixStack, Shader &shader);

// Body Maker
s_body humanMaker(void);

// Print
void printBodyToTerm(s_body &body);
void printBodyToFile(s_body &body, std::string fileName);

#endif

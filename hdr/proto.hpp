#ifndef PROTO_HPP
#define PROTO_HPP


#include "./HumanGL.hpp"

// input
void processInput(GLFWwindow *window);

// Draw human
void	drawLimb(Limb *limb, MatrixStack &matrixStack, Shader &shader);

// Body Maker
Limb *humanMaker(void);

// Print
void printBodyToTerm(Limb *limb);
void printBodyToFile(Limb *limb, std::string fileName);

#endif

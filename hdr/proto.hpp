#ifndef PROTO_HPP
#define PROTO_HPP


#include "./HumanGL.hpp"

// input
void processInput(GLFWwindow *window, s_body &body, float deltaTime);

// Draw human
void	drawLimb(Limb *limb, int &limbIndex, int selectedLimb, MatrixStack &matrixStack, Shader &shader);

// Body Maker
s_body humanMaker(void);
void updateBody(std::vector<Limb*> &limbs, const int size, std::vector<std::array<Matrix4, 2>> anim);

// Print
void printBodyToTerm(s_body &body);
void printBodyToFile(s_body &body, std::string fileName);

#endif

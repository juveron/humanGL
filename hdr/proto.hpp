#ifndef PROTO_HPP
#define PROTO_HPP


#include "./HumanGL.hpp"

// input
void processInput(GLFWwindow *window, s_body &body, float deltaTime, s_animationData &stuff, int &currentIndex);

// Draw human
void	drawLimb(Limb *limb, int &limbIndex, int selectedLimb, MatrixStack &matrixStack, Shader &shader, unsigned int *textures);

// Body Maker
s_body humanMaker(void);
s_body doggoMaker(void);
void updateBody(std::vector<Limb*> &limbs, const int size, std::vector<std::array<Matrix4, 3>> anim);
void positionHumanLimbs(std::vector<Limb*> &limbs);
void positionDoggoLimbs(std::vector<Limb*> &limbs);


// init body/Limb
void	initBody(s_body &body, int &currentIndex);
void	initLimb(s_body &body, int &currentIndex);

// Print
void printBodyToTerm(s_body &body);
void printBodyToFile(s_body &body, std::string fileName);

// Aniamtion
void animateBody(s_body &body, std::vector<ANIMATION_FRAME> anim, float animationTime, s_animationData &animationData, int bodyIndex);

// Texture
unsigned int *generateTextures(std::vector<const char *> texturePaths);

#endif

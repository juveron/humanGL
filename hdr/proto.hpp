#ifndef PROTO_HPP
#define PROTO_HPP


#include "HumanGL.hpp"

// input
void processInput(GLFWwindow *window, ABody *body, float deltaTime, s_animationData &stuff, s_indexBody &indexBody);

// Texture
unsigned int *generateTextures(std::vector<char const *> texturePaths);

// Lerp
float lerp(float a, float b, float t);
Vector3f lerp(Vector3f a, Vector3f b, float t);


#endif

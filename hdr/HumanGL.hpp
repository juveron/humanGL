#ifndef HUMANGL_HPP
#define HUMANGL_HPP

#include "../glad/include/glad/glad.h"
#include <GLFW/glfw3.h>

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <stack>
#include <array>
#include <map>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define PI 3.14159265
#define ANIMATION_FRAME std::vector<std::array<Matrix4, 3>>

#include "./struct.hpp"
#include "./classes.hpp"
#include "./proto.hpp"

extern std::vector<ANIMATION_FRAME> walkingAnim;
extern std::vector<ANIMATION_FRAME> sittingDogAnim;

extern float walkingTime;
extern float sittingDogTime;

#endif

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

#include <ft2build.h>
#include FT_FREETYPE_H


#define SCREEN_WIDTH 1200
#define SCREEN_WIDTH_UI 400
#define SCREEN_WIDTH_BODIES 800
#define SCREEN_HEIGHT 600
#define PI 3.14159265

#define ALIGN_LEFT 0x0001
#define ALIGN_CENTER 0x0002
#define ALIGN_RIGHT 0x0003

#define NO_RENDER_TEXT 0x0010
#define REGULAR_TEXT 0x0011
#define UNDERLINE_TEXT 0x0012

#define ANIMATION_FRAME std::vector<std::array<Vector3f, 3>>

#include "./struct.hpp"
#include "./classes.hpp"
#include "./proto.hpp"

// Human animations
extern Animation walkingHumanAnimation;
extern Animation jumpingHumanAnimation;
extern Animation flossingHumanAnimation;

// Doggo animations
extern Animation jumpingDoggoAnimation;
extern Animation tailChasingDoggoAnimation;
extern Animation walkingOnFrontLegsAnimation;
extern Animation walkingOnHindLegsAnimation;

extern float walkingTime;
extern float sittingDogTime;

#endif

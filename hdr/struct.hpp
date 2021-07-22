#ifndef STRUCT_HPP
#define STRUCT_HPP

#include "./HumanGL.hpp"

class Limb;

typedef enum				axis {
	X_AXIS,
	Y_AXIS,
	Z_AXIS
}							e_axis;

typedef struct				body {
	Limb					*limb;
	std::vector<Limb *>		limbs;
}							s_body;

#endif

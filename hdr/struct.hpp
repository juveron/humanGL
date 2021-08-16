#ifndef STRUCT_HPP
#define STRUCT_HPP

#include "./HumanGL.hpp"

class Limb;

typedef enum				axis {
	X_AXIS,
	Y_AXIS,
	Z_AXIS
}							e_axis;

typedef enum	humanBody {
	TORSO,
	HEAD,
	RIGHT_ARM,
	RIGHT_FOREARM,
	// RIGHT_HAND,
	LEFT_ARM,
	LEFT_FOREARM,
	// LEFT_HAND,
	RIGHT_THIGH,
	RIGHT_LEG,
	// RIGHT_FOOT,
	LEFT_THIGH,
	LEFT_LEG,
	// LEFT_FOOT
}				e_humanBody;

typedef struct				body {
	int						selectedLimb;
	Limb					*limb;
	std::vector<Limb *>		limbs;
}							s_body;

#endif

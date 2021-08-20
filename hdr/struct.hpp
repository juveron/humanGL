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
	LEFT_ARM,
	LEFT_FOREARM,
	RIGHT_THIGH,
	RIGHT_LEG,
	LEFT_THIGH,
	LEFT_LEG,
}				e_humanBody;

typedef enum class	DoggoBody {
	TORSO,
	LOW_TORSO,
	HEAD,
	MUZZLE,
	RIGHT_EAR,
	LEFT_EAR,
	TAIL,
	RIGHT_UPPER_PAW,
	LEFT_UPPER_PAW,
	RIGHT_LOW_PAW,
	LEFT_LOW_PAW,
}				e_DoggoBody;

typedef struct				body {
	int						selectedLimb;
	Limb					*limb;
	std::vector<Limb *>		limbs;
}							s_body;

typedef struct				animationData {
	bool					isAnimated;
	float					animationTime;
	int						animationIndex;
}							s_animationData;

#endif

#ifndef STRUCT_HPP
#define STRUCT_HPP

#include "HumanGL.hpp"

class Limb;

typedef enum				axis {
	X_AXIS,
	Y_AXIS,
	Z_AXIS
}							e_axis;

namespace human {
	typedef enum			humanBody {
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
	}						e_humanBody;
}

namespace doggo {
	typedef enum			DoggoBody {
		TORSO,
		LOW_TORSO,
		TAIL,
		RIGHT_LOW_PAW,
		LEFT_LOW_PAW,
		RIGHT_UPPER_PAW,
		LEFT_UPPER_PAW,
		HEAD,
		MUZZLE,
		RIGHT_EAR,
		LEFT_EAR,
	}						e_DoggoBody;
}

typedef struct				body {
	int						selectedLimb;
	Limb					*limb;
	std::vector<Limb *>		limbs;
}							s_body;

typedef struct				indexBody {
	unsigned char			drawBody = 1;
	int 					modelIndex = 0;
}							s_indexBody;

typedef struct				animationData {
	bool					isAnimated;
	size_t					animationIndex;
}							s_animationData;

typedef struct				textureData {
	unsigned char *			data;
	int						width;
	int						height;
	int						nbrChannels;
}							s_textureData;

#endif

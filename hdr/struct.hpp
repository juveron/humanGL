#ifndef STRUCT_HPP
#define STRUCT_HPP

#include "HumanGL.hpp"

#include "./class/Vector2f.hpp"
#include "./class/Vector3f.hpp"

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

typedef struct				indexBody {
	unsigned char			drawBody = 1;
	int 					modelIndex = 0;
}							s_indexBody;

typedef struct				textureInfo {
	unsigned char *			data;
	int						width;
	int						height;
	int						nbrChannels;
}							s_textureInfo;

typedef struct				Character {
	unsigned int			textureId;
	Vector2f				size;
	Vector2f				bearing;
	unsigned int			advance;
}							s_Charater;

typedef struct				textInformation {
	std::string				data;
	unsigned int			alignMode;
	unsigned int			textMode;
	float					scale;
	Vector3f				color;
}							s_textInformation;

#endif

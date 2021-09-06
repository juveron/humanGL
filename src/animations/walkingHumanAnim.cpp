#include "HumanGL.hpp"

static std::vector<ANIMATION_FRAME> animation{
	{
		{ Vector3f(0,94.0599,0), Vector3f(-5,-2.5,0), Vector3f(1,1,1) },
		{ Vector3f(0,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(0,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(0,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(0,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(0,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(0,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(0,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(0,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(0,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
	},
	{
		{ Vector3f(0,94.0599,0), Vector3f(-2.5,-2.5,0), Vector3f(1,1,1) },
		{ Vector3f(0,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(-42.3362,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(0,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(34.8565,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(0,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(25.4515,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(0,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(-35.9854,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(0,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
	},
	{
		{ Vector3f(0,94.0599,0), Vector3f(0,-2.5,0), Vector3f(1,1,1) },
		{ Vector3f(0,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(30.336,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(0,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(-51.6982,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(0,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(-36.7479,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(0,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(30.7051,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(0,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
	},
	{
		{ Vector3f(0,85.1115,0), Vector3f(2.5,-2.5,0), Vector3f(1,1,1) },
		{ Vector3f(0,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(-48.333,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(0,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(46.4632,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(0,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(29.5649,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(0,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(-49.8474,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(0,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
	},
	{
		{ Vector3f(0,85.1115,0), Vector3f(5,-2.5,0), Vector3f(1,1,1) },
		{ Vector3f(0,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(0,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(0,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(0,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(0,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(0,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(0,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(0,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(0,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
	},
};

Animation walkingHumanAnimation(3.0f, animation);

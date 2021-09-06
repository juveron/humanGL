#include "HumanGL.hpp"

static std::vector<ANIMATION_FRAME> animation{
	{
		{ Vector3f(0,2.16732,0), Vector3f(-0.25,-2.25,0), Vector3f(1,1,1) },
		{ Vector3f(0,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(20,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(-70,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(20,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(-70,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(-40,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(70,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(-40,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(70,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
	},
	{
		{ Vector3f(0,2.16732,0), Vector3f(-0.25,-2,0), Vector3f(1,1,1) },
		{ Vector3f(0,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(-70.0272,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(0,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(-66.6213,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(0,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(0,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(0,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(0,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(0,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
	},
	{
		{ Vector3f(0,2.16732,0), Vector3f(-0.25,-1,0), Vector3f(1,1,1) },
		{ Vector3f(0,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(-167.442,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(-0.0570221,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(-164.726,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(-0.0582962,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(-0.0334358,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(0.0615005,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(-0.0340919,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(0.059288,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
	},
	{
		{ Vector3f(0,2.16732,0), Vector3f(-0.25,0,0), Vector3f(1,1,1) },
		{ Vector3f(0,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(-167.442,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(-0.0570221,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(-164.726,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(-0.0582962,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(-0.0334358,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(0.0615005,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(-0.0340919,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(0.059288,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
	},
	{
		{ Vector3f(0,2.16732,0), Vector3f(-0.25,-1,0), Vector3f(1,1,1) },
		{ Vector3f(0,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(-167.442,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(-0.0570221,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(-164.726,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(-0.0582962,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(-0.0334358,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(0.0615005,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(-0.0340919,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(0.059288,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
	},
	{
		{ Vector3f(0,2.16732,0), Vector3f(-0.25,-1.97466,0), Vector3f(1,1,1) },
		{ Vector3f(0,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(-70.0272,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(0,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(-66.6213,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(0,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(0,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(0,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(0,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(0,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
	},
	{
		{ Vector3f(0,2.16732,0), Vector3f(-0.25,-2.24033,0), Vector3f(1,1,1) },
		{ Vector3f(0,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(19.4534,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(-67.0413,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(18.7241,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(-68.5375,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(-39.3085,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(72.3017,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(-40.0828,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
		{ Vector3f(69.7048,0,0), Vector3f(0,0,0), Vector3f(1,1,1) },
	},
};

Animation jumpingHumanAnimation(1.5f, animation);
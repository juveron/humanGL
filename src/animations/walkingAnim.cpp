#include "HumanGL.hpp"

float walkingTime = 2.0f;

std::vector<ANIMATION_FRAME> walkingAnim{
	{
	{ Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 }), Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 }), Matrix4((float const []) { 1, 0, 0, 0, 0, 1.5, 0, 0, 0, 0, 0.5, 0, 0, 0, 0, 1 }) },
	{ Matrix4((float const []) { 1, 0, 0, 0, 0, -1, 3.58979e-09, 0, 0, -3.58979e-09, -1, 0, 0, 0, 0, 1 }), Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 }), Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 }) },
	{ Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 }), Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0.75, 0, 0, 1 }), Matrix4((float const []) { 0.5, 0, 0, 0, 0, 0.75, 0, 0, 0, 0, 0.5, 0, 0, 0, 0, 1 }) },
	{ Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 }), Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, -0.75, 0, 1 }), Matrix4((float const []) { 0.5, 0, 0, 0, 0, 0.75, 0, 0, 0, 0, 0.5, 0, 0, 0, 0, 1 }) },
	{ Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 }), Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, -0.75, 0, 0, 1 }), Matrix4((float const []) { 0.5, 0, 0, 0, 0, 0.75, 0, 0, 0, 0, 0.5, 0, 0, 0, 0, 1 }) },
	{ Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 }), Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, -0.75, 0, 1 }), Matrix4((float const []) { 0.5, 0, 0, 0, 0, 0.75, 0, 0, 0, 0, 0.5, 0, 0, 0, 0, 1 }) },
	{ Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 }), Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0.25, -1.5, 0, 1 }), Matrix4((float const []) { 0.5, 0, 0, 0, 0, 0.75, 0, 0, 0, 0, 0.5, 0, 0, 0, 0, 1 }) },
	{ Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 }), Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, -0.75, 0, 1 }), Matrix4((float const []) { 0.5, 0, 0, 0, 0, 0.75, 0, 0, 0, 0, 0.5, 0, 0, 0, 0, 1 }) },
	{ Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 }), Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, -0.25, -1.5, 0, 1 }), Matrix4((float const []) { 0.5, 0, 0, 0, 0, 0.75, 0, 0, 0, 0, 0.5, 0, 0, 0, 0, 1 }) },
	{ Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 }), Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, -0.75, 0, 1 }), Matrix4((float const []) { 0.5, 0, 0, 0, 0, 0.75, 0, 0, 0, 0, 0.5, 0, 0, 0, 0, 1 }) },
},
	{
	{ Matrix4((float const []) { 0.203029, 0, -0.979173, 0, 0, 1, 0, 0, 0.979173, 0, 0.203029, 0, 0, 0, 0, 1 }), Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 }), Matrix4((float const []) { 1, 0, 0, 0, 0, 1.5, 0, 0, 0, 0, 0.5, 0, 0, 0, 0, 1 }) },
	{ Matrix4((float const []) { 1, 0, 0, 0, 0, -1, 3.58979e-09, 0, 0, -3.58979e-09, -1, 0, 0, 0, 0, 1 }), Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 }), Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 }) },
	{ Matrix4((float const []) { 1, 0, 0, 0, 0, 0.933844, -0.357681, 0, 0, 0.357681, 0.933844, 0, 0, 0, 0, 1 }), Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0.75, 0, 0, 1 }), Matrix4((float const []) { 0.5, 0, 0, 0, 0, 0.75, 0, 0, 0, 0, 0.5, 0, 0, 0, 0, 1 }) },
	{ Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 }), Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, -0.75, 0, 1 }), Matrix4((float const []) { 0.5, 0, 0, 0, 0, 0.75, 0, 0, 0, 0, 0.5, 0, 0, 0, 0, 1 }) },
	{ Matrix4((float const []) { 1, 0, 0, 0, 0, 0.936132, 0.35165, 0, 0, -0.35165, 0.936132, 0, 0, 0, 0, 1 }), Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, -0.75, 0, 0, 1 }), Matrix4((float const []) { 0.5, 0, 0, 0, 0, 0.75, 0, 0, 0, 0, 0.5, 0, 0, 0, 0, 1 }) },
	{ Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 }), Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, -0.75, 0, 1 }), Matrix4((float const []) { 0.5, 0, 0, 0, 0, 0.75, 0, 0, 0, 0, 0.5, 0, 0, 0, 0, 1 }) },
	{ Matrix4((float const []) { 1, 0, 0, 0, 0, 0.955369, -0.295415, 0, 0, 0.295415, 0.955369, 0, 0, 0, 0, 1 }), Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0.25, -1.5, 0, 1 }), Matrix4((float const []) { 0.5, 0, 0, 0, 0, 0.75, 0, 0, 0, 0, 0.5, 0, 0, 0, 0, 1 }) },
	{ Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 }), Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, -0.75, 0, 1 }), Matrix4((float const []) { 0.5, 0, 0, 0, 0, 0.75, 0, 0, 0, 0, 0.5, 0, 0, 0, 0, 1 }) },
	{ Matrix4((float const []) { 1, 0, 0, 0, 0, 0.971109, 0.238637, 0, 0, -0.238637, 0.971109, 0, 0, 0, 0, 1 }), Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, -0.25, -1.5, 0, 1 }), Matrix4((float const []) { 0.5, 0, 0, 0, 0, 0.75, 0, 0, 0, 0, 0.5, 0, 0, 0, 0, 1 }) },
	{ Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 }), Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, -0.75, 0, 1 }), Matrix4((float const []) { 0.5, 0, 0, 0, 0, 0.75, 0, 0, 0, 0, 0.5, 0, 0, 0, 0, 1 }) },
},{
	{ Matrix4((float const []) { 0.203029, 0, -0.979173, 0, 0, 1, 0, 0, 0.979173, 0, 0.203029, 0, 0, 0, 0, 1 }), Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 }), Matrix4((float const []) { 1, 0, 0, 0, 0, 1.5, 0, 0, 0, 0, 0.5, 0, 0, 0, 0, 1 }) },
	{ Matrix4((float const []) { 1, 0, 0, 0, 0, -1, 3.58979e-09, 0, 0, -3.58979e-09, -1, 0, 0, 0, 0, 1 }), Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 }), Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 }) },
	{ Matrix4((float const []) { 1, 0, 0, 0, 0, 0.81335, -0.581775, 0, 0, 0.581775, 0.81335, 0, 0, 0, 0, 1 }), Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0.75, 0, 0, 1 }), Matrix4((float const []) { 0.5, 0, 0, 0, 0, 0.75, 0, 0, 0, 0, 0.5, 0, 0, 0, 0, 1 }) },
	{ Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 }), Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, -0.75, 0, 1 }), Matrix4((float const []) { 0.5, 0, 0, 0, 0, 0.75, 0, 0, 0, 0, 0.5, 0, 0, 0, 0, 1 }) },
	{ Matrix4((float const []) { 1, 0, 0, 0, 0, 0.785644, 0.618679, 0, 0, -0.618679, 0.785644, 0, 0, 0, 0, 1 }), Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, -0.75, 0, 0, 1 }), Matrix4((float const []) { 0.5, 0, 0, 0, 0, 0.75, 0, 0, 0, 0, 0.5, 0, 0, 0, 0, 1 }) },
	{ Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 }), Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, -0.75, 0, 1 }), Matrix4((float const []) { 0.5, 0, 0, 0, 0, 0.75, 0, 0, 0, 0, 0.5, 0, 0, 0, 0, 1 }) },
	{ Matrix4((float const []) { 1, 0, 0, 0, 0, 0.824955, -0.565198, 0, 0, 0.565198, 0.824955, 0, 0, 0, 0, 1 }), Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0.25, -1.5, 0, 1 }), Matrix4((float const []) { 0.5, 0, 0, 0, 0, 0.75, 0, 0, 0, 0, 0.5, 0, 0, 0, 0, 1 }) },
	{ Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 }), Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, -0.75, 0, 1 }), Matrix4((float const []) { 0.5, 0, 0, 0, 0, 0.75, 0, 0, 0, 0, 0.5, 0, 0, 0, 0, 1 }) },
	{ Matrix4((float const []) { 1, 0, 0, 0, 0, 0.89766, 0.44069, 0, 0, -0.44069, 0.89766, 0, 0, 0, 0, 1 }), Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, -0.25, -1.5, 0, 1 }), Matrix4((float const []) { 0.5, 0, 0, 0, 0, 0.75, 0, 0, 0, 0, 0.5, 0, 0, 0, 0, 1 }) },
	{ Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 }), Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, -0.75, 0, 1 }), Matrix4((float const []) { 0.5, 0, 0, 0, 0, 0.75, 0, 0, 0, 0, 0.5, 0, 0, 0, 0, 1 }) },
},	{
	{ Matrix4((float const []) { 0.203029, 0, -0.979173, 0, 0, 1, 0, 0, 0.979173, 0, 0.203029, 0, 0, 0, 0, 1 }), Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 }), Matrix4((float const []) { 1, 0, 0, 0, 0, 1.5, 0, 0, 0, 0, 0.5, 0, 0, 0, 0, 1 }) },
	{ Matrix4((float const []) { 1, 0, 0, 0, 0, -1, 3.58979e-09, 0, 0, -3.58979e-09, -1, 0, 0, 0, 0, 1 }), Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 }), Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 }) },
	{ Matrix4((float const []) { 1, 0, 0, 0, 0, 0.933844, -0.357681, 0, 0, 0.357681, 0.933844, 0, 0, 0, 0, 1 }), Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0.75, 0, 0, 1 }), Matrix4((float const []) { 0.5, 0, 0, 0, 0, 0.75, 0, 0, 0, 0, 0.5, 0, 0, 0, 0, 1 }) },
	{ Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 }), Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, -0.75, 0, 1 }), Matrix4((float const []) { 0.5, 0, 0, 0, 0, 0.75, 0, 0, 0, 0, 0.5, 0, 0, 0, 0, 1 }) },
	{ Matrix4((float const []) { 1, 0, 0, 0, 0, 0.936132, 0.35165, 0, 0, -0.35165, 0.936132, 0, 0, 0, 0, 1 }), Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, -0.75, 0, 0, 1 }), Matrix4((float const []) { 0.5, 0, 0, 0, 0, 0.75, 0, 0, 0, 0, 0.5, 0, 0, 0, 0, 1 }) },
	{ Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 }), Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, -0.75, 0, 1 }), Matrix4((float const []) { 0.5, 0, 0, 0, 0, 0.75, 0, 0, 0, 0, 0.5, 0, 0, 0, 0, 1 }) },
	{ Matrix4((float const []) { 1, 0, 0, 0, 0, 0.955369, -0.295415, 0, 0, 0.295415, 0.955369, 0, 0, 0, 0, 1 }), Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0.25, -1.5, 0, 1 }), Matrix4((float const []) { 0.5, 0, 0, 0, 0, 0.75, 0, 0, 0, 0, 0.5, 0, 0, 0, 0, 1 }) },
	{ Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 }), Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, -0.75, 0, 1 }), Matrix4((float const []) { 0.5, 0, 0, 0, 0, 0.75, 0, 0, 0, 0, 0.5, 0, 0, 0, 0, 1 }) },
	{ Matrix4((float const []) { 1, 0, 0, 0, 0, 0.971109, 0.238637, 0, 0, -0.238637, 0.971109, 0, 0, 0, 0, 1 }), Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, -0.25, -1.5, 0, 1 }), Matrix4((float const []) { 0.5, 0, 0, 0, 0, 0.75, 0, 0, 0, 0, 0.5, 0, 0, 0, 0, 1 }) },
	{ Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 }), Matrix4((float const []) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, -0.75, 0, 1 }), Matrix4((float const []) { 0.5, 0, 0, 0, 0, 0.75, 0, 0, 0, 0, 0.5, 0, 0, 0, 0, 1 }) },
},
};

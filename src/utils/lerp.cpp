#include "HumanGL.hpp"

float lerp(float a, float b, float t)
{
	return (a + t * (b - a));
}

Vector3f lerp(Vector3f a, Vector3f b, float t)
{
	return (a + (b - a) * t);
}

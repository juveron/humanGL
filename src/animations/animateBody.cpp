#include "HumanGL.hpp"

static float lerp(float a, float b, float t)
{
	return (a + t * (b - a));
}

void animateBody(s_body &body, std::vector<ANIMATION_FRAME> anim, float animationTime, s_animationData &animationData, int bodyIndex)
{
	ANIMATION_FRAME currentFrameData;

	float timePerFrame = animationTime / (anim.size() - 1);

	float currentFrame = animationData.animationTime / timePerFrame;
	float prevFrame = std::floor(currentFrame);
	float nextFrame = std::ceil(currentFrame);
	float framePercentage = std::fmod(currentFrame, 1);

	size_t i = 0;
	if (nextFrame < anim.size()) {
		Vector3f rotation;
		Vector3f translation;
		Vector3f scale;

		while (i < anim[prevFrame].size())
		{

			rotation.x = lerp(anim[prevFrame][i][0].x, anim[nextFrame][i][0].x, framePercentage);
			rotation.y = lerp(anim[prevFrame][i][0].y, anim[nextFrame][i][0].y, framePercentage);
			rotation.z = lerp(anim[prevFrame][i][0].z, anim[nextFrame][i][0].z, framePercentage);

			translation.x = lerp(anim[prevFrame][i][1].x, anim[nextFrame][i][1].x, framePercentage);
			translation.y = lerp(anim[prevFrame][i][1].y, anim[nextFrame][i][1].y, framePercentage);
			translation.z = lerp(anim[prevFrame][i][1].z, anim[nextFrame][i][1].z, framePercentage);

			scale.x = lerp(anim[prevFrame][i][2].x, anim[nextFrame][i][2].x, framePercentage);
			scale.y = lerp(anim[prevFrame][i][2].y, anim[nextFrame][i][2].y, framePercentage);
			scale.z = lerp(anim[prevFrame][i][2].z, anim[nextFrame][i][2].z, framePercentage);
			currentFrameData.push_back({ rotation, translation, scale });
			i++;
		}
		updateBody(body, currentFrameData, bodyIndex);
	}
	else {
		animationData.isAnimated = false;
	}
}

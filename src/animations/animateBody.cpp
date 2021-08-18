#include "HumanGL.hpp"

static float lerp(float a, float b, float t)
{
	return (a + t * (b - a));
}

void animateBody(s_body &body, std::vector<ANIMATION_FRAME> anim, float animFrame)
{
	ANIMATION_FRAME currentFrameData;

	float prevFrame = std::floor(animFrame);
	float nextFrame = std::ceil(animFrame);
	float framePercentage = std::fmod(animFrame, 1);

	size_t i = 0;
	if (nextFrame < anim.size())
	{
		Matrix4 rotateMat;
		Matrix4 translateMat;
		Matrix4 scaleMat;
		while (i < anim[prevFrame].size())
		{

			int j = 0;
			while (j < 16)
			{
				rotateMat.matrix[j] = lerp(anim[prevFrame][i][0].matrix[j], anim[nextFrame][i][0].matrix[j], framePercentage);
				translateMat.matrix[j] = lerp(anim[prevFrame][i][1].matrix[j], anim[nextFrame][i][1].matrix[j], framePercentage);
				scaleMat.matrix[j] = lerp(anim[prevFrame][i][2].matrix[j], anim[nextFrame][i][2].matrix[j], framePercentage);
				j++;
			}

			currentFrameData.push_back({ rotateMat, translateMat, scaleMat });
			i++;
		}
		updateBody(body.limbs, body.limbs.size(), currentFrameData);
	}
	else {
		initBody(body);
	}
}

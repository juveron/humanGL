#include "HumanGL.hpp"

void updateBody(s_body body, ANIMATION_FRAME anim, int currentIndex)
{
	size_t i = 0;
	std::vector<Limb*> limbs = body.limbs;
	size_t size = limbs.size();

	while (i < size)
	{
		limbs[i]->rotation.x = anim[i][0].x;
		limbs[i]->rotation.y = anim[i][0].y;
		limbs[i]->rotation.z = anim[i][0].z;
		limbs[i]->translation.x = anim[i][1].x;
		limbs[i]->translation.y = anim[i][1].y;
		limbs[i]->translation.z = anim[i][1].z;
		limbs[i]->scale.x = anim[i][2].x;
		limbs[i]->scale.y = anim[i][2].y;
		limbs[i]->scale.z = anim[i][2].z;
		i++;
	}
	if (currentIndex == 0) positionHumanLimbs(body.limbs); else positionDoggoLimbs(body.limbs);
}

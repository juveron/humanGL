#include "HumanGL.hpp"

void updateBody(std::vector<Limb*> &limbs, const int size, std::vector<std::array<Matrix4, 3>> anim)
{
	int i = 0;

	while (i < size)
	{
		limbs[i]->rotateMat = anim[i][0];
		limbs[i]->translateMat = anim[i][1];
		limbs[i]->translation.x = anim[i][1].matrix[12];
		limbs[i]->translation.y = anim[i][1].matrix[14];
		limbs[i]->translation.z = anim[i][1].matrix[13];
		limbs[i]->scaleMat = anim[i][2];
		limbs[i]->scale.x = anim[i][2].matrix[0];
		limbs[i]->scale.y = anim[i][2].matrix[5];
		limbs[i]->scale.z = anim[i][2].matrix[10];
		i++;
	}
}

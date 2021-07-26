#include "../../hdr/HumanGL.hpp"

void updateBody(Limb limbs[], const int size, std::vector<std::array<Matrix4, 2>> anim)
{
	int i = 0;

	while (i < size)
	{
		limbs[i].currentMat = anim[i][0];
		limbs[i].scaleMat = anim[i][1];
		limbs[i].scale.x = anim[i][1].matrix[0];
		limbs[i].scale.y = anim[i][1].matrix[5];
		limbs[i].scale.z = anim[i][1].matrix[10];
		i++;
	}
}

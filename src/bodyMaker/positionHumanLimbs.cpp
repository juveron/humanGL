#include "HumanGL.hpp"


void positionHumanLimbs(std::vector<Limb*> &limbs)
{
	size_t i = 0;
	Matrix4 tmp;
	while (i < limbs.size())
	{
		limbs[i]->translateMat = Matrix4::newIdentityMatrix();
		tmp = Matrix4::newIdentityMatrix();

		switch (i)
		{
		case HEAD:
			break;
		case RIGHT_ARM:
			tmp.translate(0.5f * limbs[RIGHT_ARM]->scale.x + 0.5f * limbs[RIGHT_ARM]->parent->scale.x, 0.0f, 0.0f);
			break;
		case RIGHT_FOREARM:
			tmp.translate(0.0f, -limbs[RIGHT_FOREARM]->parent->scale.y, 0.0f);
			break;
		case RIGHT_HAND:
			tmp.translate(0.0f, -limbs[RIGHT_HAND]->parent->scale.y, 0.0f);
			break;
		case LEFT_ARM:
			tmp.translate(-(0.5f * limbs[LEFT_ARM]->scale.x + 0.5f * limbs[LEFT_ARM]->parent->scale.x), 0.0f, 0.0f);
			break;
		case LEFT_FOREARM:
			tmp.translate(0.0f, -limbs[LEFT_FOREARM]->parent->scale.y, 0.0f);
			break;
		case LEFT_HAND:
			tmp.translate(0.0f, -limbs[LEFT_HAND]->parent->scale.y, 0.0f);
			break;
		case RIGHT_THIGH:
			tmp.translate(0.5f * limbs[RIGHT_THIGH]->scale.x, -limbs[RIGHT_THIGH]->parent->scale.y, 0.0f);
			break;
		case RIGHT_LEG:
			tmp.translate(0.0f, -limbs[RIGHT_LEG]->parent->scale.y, 0.0f);
			break;
		case RIGHT_FOOT:
			tmp.translate(0.0f, -limbs[RIGHT_FOOT]->parent->scale.y, 0.15f);
			break;
		case LEFT_THIGH:
			tmp.translate(-0.5f * limbs[LEFT_THIGH]->scale.x, -limbs[LEFT_THIGH]->parent->scale.y, 0.0f);
			break;
		case LEFT_LEG:
			tmp.translate(0.0f, -limbs[LEFT_LEG]->parent->scale.y, 0.0f);
			break;
		case LEFT_FOOT:
			tmp.translate(0.0f, -limbs[LEFT_FOOT]->parent->scale.y, 0.15f);
			break;
		default:
			break;
		}
		tmp.translate(limbs[i]->translation.x, limbs[i]->translation.y, limbs[i]->translation.z);
		limbs[i]->translateMat = tmp;
		i++;
	}
}

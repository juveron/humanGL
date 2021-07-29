#include "HumanGL.hpp"

void positionHumanLimbs(std::vector<Limb *> &limbs)
{
	size_t i = 0;

	Matrix4 tmpRotate;
	Matrix4 tmpTranslate;
	Matrix4 tmpScale;

	while (i < limbs.size())
	{
		limbs[i]->rotateMat = Matrix4::newIdentityMatrix();
		limbs[i]->translateMat = Matrix4::newIdentityMatrix();
		limbs[i]->scaleMat = Matrix4::newIdentityMatrix();

		tmpRotate = Matrix4::newIdentityMatrix();
		tmpTranslate = Matrix4::newIdentityMatrix();
		tmpScale = Matrix4::newIdentityMatrix();

		switch (i)
		{
		case TORSO:
			tmpScale.scale(limbs[i]->baseScale.x, limbs[i]->baseScale.y, limbs[i]->baseScale.z);
			break;
		case HEAD:
			tmpRotate.rotate(180, X_AXIS);
			tmpScale.scale(limbs[i]->baseScale.x, limbs[i]->baseScale.y, limbs[i]->baseScale.z);
			break;
		case RIGHT_ARM:
			tmpTranslate.translate(0.5f * limbs[RIGHT_ARM]->baseScale.x + 0.5f * limbs[RIGHT_ARM]->parent->baseScale.x * limbs[RIGHT_ARM]->parent->scale.x, 0.0f, 0.0f);
			tmpScale.scale(limbs[i]->baseScale.x, limbs[i]->baseScale.y, limbs[i]->baseScale.z);
			break;
		case RIGHT_FOREARM:
			tmpTranslate.translate(0.0f, -limbs[RIGHT_FOREARM]->parent->baseScale.y * limbs[RIGHT_FOREARM]->parent->scale.y, 0.0f);
			tmpScale.scale(limbs[i]->baseScale.x, limbs[i]->baseScale.y, limbs[i]->baseScale.z);
			break;
		case RIGHT_HAND:
			tmpTranslate.translate(0.0f, -limbs[RIGHT_HAND]->parent->baseScale.y * limbs[RIGHT_HAND]->parent->scale.y, 0.0f);
			tmpScale.scale(limbs[i]->baseScale.x, limbs[i]->baseScale.y, limbs[i]->baseScale.z);
			break;
		case LEFT_ARM:
			tmpTranslate.translate(-(0.5f * limbs[LEFT_ARM]->baseScale.x + 0.5f * limbs[LEFT_ARM]->parent->baseScale.x * limbs[LEFT_ARM]->parent->scale.x), 0.0f, 0.0f);
			tmpScale.scale(limbs[i]->baseScale.x, limbs[i]->baseScale.y, limbs[i]->baseScale.z);
			break;
		case LEFT_FOREARM:
			tmpTranslate.translate(0.0f, -limbs[LEFT_FOREARM]->parent->baseScale.y * limbs[LEFT_FOREARM]->parent->scale.y, 0.0f);
			tmpScale.scale(limbs[i]->baseScale.x, limbs[i]->baseScale.y, limbs[i]->baseScale.z);
			break;
		case LEFT_HAND:
			tmpTranslate.translate(0.0f, -limbs[LEFT_HAND]->parent->baseScale.y * limbs[LEFT_HAND]->parent->scale.y, 0.0f);
			tmpScale.scale(limbs[i]->baseScale.x, limbs[i]->baseScale.y, limbs[i]->baseScale.z);
			break;
		case RIGHT_THIGH:
			tmpTranslate.translate(0.5f * limbs[RIGHT_THIGH]->baseScale.x, -limbs[RIGHT_THIGH]->parent->baseScale.y * limbs[RIGHT_THIGH]->parent->scale.y, 0.0f);
			tmpScale.scale(limbs[i]->baseScale.x, limbs[i]->baseScale.y, limbs[i]->baseScale.z);
			break;
		case RIGHT_LEG:
			tmpTranslate.translate(0.0f, -limbs[RIGHT_LEG]->parent->baseScale.y * limbs[RIGHT_LEG]->parent->scale.y, 0.0f);
			tmpScale.scale(limbs[i]->baseScale.x, limbs[i]->baseScale.y, limbs[i]->baseScale.z);
			break;
		case RIGHT_FOOT:
			tmpTranslate.translate(0.0f, -limbs[RIGHT_FOOT]->parent->baseScale.y * limbs[RIGHT_FOOT]->parent->scale.y, 0.15f);
			tmpScale.scale(limbs[i]->baseScale.x, limbs[i]->baseScale.y, limbs[i]->baseScale.z);
			break;
		case LEFT_THIGH:
			tmpTranslate.translate(-0.5f * limbs[LEFT_THIGH]->baseScale.x, -limbs[LEFT_THIGH]->parent->baseScale.y * limbs[LEFT_THIGH]->parent->scale.y, 0.0f);
			tmpScale.scale(limbs[i]->baseScale.x, limbs[i]->baseScale.y, limbs[i]->baseScale.z);
			break;
		case LEFT_LEG:
			tmpTranslate.translate(0.0f, -limbs[LEFT_LEG]->parent->baseScale.y * limbs[LEFT_LEG]->parent->scale.y, 0.0f);
			tmpScale.scale(limbs[i]->baseScale.x, limbs[i]->baseScale.y, limbs[i]->baseScale.z);
			break;
		case LEFT_FOOT:
			tmpTranslate.translate(0.0f, -limbs[LEFT_FOOT]->parent->baseScale.y * limbs[LEFT_FOOT]->parent->scale.y, 0.15f);
			tmpScale.scale(limbs[i]->baseScale.x, limbs[i]->baseScale.y, limbs[i]->baseScale.z);
			break;
		default:
			break;
		}

		tmpRotate.rotate(limbs[i]->rotation.x, X_AXIS);
		tmpRotate.rotate(limbs[i]->rotation.y, Y_AXIS);
		tmpRotate.rotate(limbs[i]->rotation.z, Z_AXIS);
		limbs[i]->rotateMat = tmpRotate;

		tmpTranslate.translate(limbs[i]->translation.x, limbs[i]->translation.y, limbs[i]->translation.z);
		limbs[i]->translateMat = tmpTranslate;

		tmpScale.scale(limbs[i]->scale.x, limbs[i]->scale.y, limbs[i]->scale.z);
		limbs[i]->scaleMat = tmpScale;

		i++;
	}
}

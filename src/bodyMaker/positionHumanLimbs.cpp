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
		case human::TORSO:
			break;
		case human::HEAD:
			tmpRotate.rotate(180, X_AXIS);
			break;
		case human::RIGHT_ARM:
			tmpTranslate.translate(0.5f * limbs[human::RIGHT_ARM]->baseScale.x + 0.5f * limbs[human::RIGHT_ARM]->parent->baseScale.x * limbs[human::RIGHT_ARM]->parent->scale.x, 0.0f, 0.0f);
			break;
		case human::RIGHT_FOREARM:
			tmpTranslate.translate(0.0f, -limbs[human::RIGHT_FOREARM]->parent->baseScale.y * limbs[human::RIGHT_FOREARM]->parent->scale.y, 0.0f);
			break;
		case human::LEFT_ARM:
			tmpTranslate.translate(-(0.5f * limbs[human::LEFT_ARM]->baseScale.x + 0.5f * limbs[human::LEFT_ARM]->parent->baseScale.x * limbs[human::LEFT_ARM]->parent->scale.x), 0.0f, 0.0f);
			break;
		case human::LEFT_FOREARM:
			tmpTranslate.translate(0.0f, -limbs[human::LEFT_FOREARM]->parent->baseScale.y * limbs[human::LEFT_FOREARM]->parent->scale.y, 0.0f);
			break;
		case human::RIGHT_THIGH:
			tmpTranslate.translate(0.5f * limbs[human::RIGHT_THIGH]->baseScale.x, -limbs[human::RIGHT_THIGH]->parent->baseScale.y * limbs[human::RIGHT_THIGH]->parent->scale.y, 0.0f);
			break;
		case human::RIGHT_LEG:
			tmpTranslate.translate(0.0f, -limbs[human::RIGHT_LEG]->parent->baseScale.y * limbs[human::RIGHT_LEG]->parent->scale.y, 0.0f);
			break;
		case human::LEFT_THIGH:
			tmpTranslate.translate(-0.5f * limbs[human::LEFT_THIGH]->baseScale.x, -limbs[human::LEFT_THIGH]->parent->baseScale.y * limbs[human::LEFT_THIGH]->parent->scale.y, 0.0f);
			break;
		case human::LEFT_LEG:
			tmpTranslate.translate(0.0f, -limbs[human::LEFT_LEG]->parent->baseScale.y * limbs[human::LEFT_LEG]->parent->scale.y, 0.0f);
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

		tmpScale.scale(limbs[i]->baseScale.x, limbs[i]->baseScale.y, limbs[i]->baseScale.z);
		tmpScale.scale(limbs[i]->scale.x, limbs[i]->scale.y, limbs[i]->scale.z);
		limbs[i]->scaleMat = tmpScale;

		i++;
	}
}

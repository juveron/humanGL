#include "HumanGL.hpp"

void positionDoggoLimbs(std::vector<Limb *> &limbs)
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
		case doggo::TORSO:
			tmpRotate.rotate(90.0f, Z_AXIS);
			break;
		case doggo::LOW_TORSO:
			tmpTranslate.translate(-0.5f * (limbs[i]->parent->baseScale.x * limbs[i]->parent->scale.x - limbs[i]->baseScale.x * limbs[i]->scale.x),
				-limbs[i]->parent->baseScale.y * limbs[i]->parent->scale.y, 0.0f);
			break;
		case doggo::TAIL:
			tmpTranslate.translate(0.5f * limbs[i]->parent->baseScale.x * limbs[i]->parent->scale.x - 0.5f * limbs[i]->baseScale.x * limbs[i]->scale.x,
				-limbs[i]->parent->baseScale.y * limbs[i]->parent->scale.y, 0.0f);
			break;
		case doggo::RIGHT_LOW_PAW:
			tmpRotate.rotate(-90.0f, Z_AXIS);
			tmpTranslate.translate(
				-0.5f * limbs[i]->parent->baseScale.x * limbs[i]->parent->scale.x,
				-0.9f * limbs[i]->parent->baseScale.y * limbs[i]->parent->scale.y + 0.5f * limbs[i]->baseScale.x * limbs[i]->scale.x,
				-(0.5f * limbs[i]->parent->baseScale.z * limbs[i]->parent->scale.z - 0.5f * limbs[i]->baseScale.z * limbs[i]->scale.z));
			break;
		case doggo::LEFT_LOW_PAW:
			tmpRotate.rotate(-90.0f, Z_AXIS);
			tmpTranslate.translate(-0.5f * limbs[i]->parent->baseScale.x * limbs[i]->parent->scale.x,
				-0.9f * limbs[i]->parent->baseScale.y * limbs[i]->parent->scale.y + 0.5f * limbs[i]->baseScale.x * limbs[i]->scale.x,
				0.5f * limbs[i]->parent->baseScale.z * limbs[i]->parent->scale.z - 0.5f * limbs[i]->baseScale.z * limbs[i]->scale.z);
			break;
		case doggo::RIGHT_UPPER_PAW:
			tmpRotate.rotate(-90.0f, Z_AXIS);
			tmpTranslate.translate(-0.5f * limbs[i]->parent->baseScale.x * limbs[i]->parent->scale.x,
				-0.3f * limbs[i]->parent->baseScale.y * limbs[i]->parent->scale.y - 0.5f * limbs[i]->baseScale.x * limbs[i]->scale.x,
				-(0.5f * limbs[i]->parent->baseScale.z * limbs[i]->parent->scale.z - 0.5f * limbs[i]->baseScale.z * limbs[i]->scale.z));
			break;
		case doggo::LEFT_UPPER_PAW:
			tmpRotate.rotate(-90.0f, Z_AXIS);
			tmpTranslate.translate(-0.5f * limbs[i]->parent->baseScale.x * limbs[i]->parent->scale.x,
				-0.3f * limbs[i]->parent->baseScale.y * limbs[i]->parent->scale.y - 0.5f * limbs[i]->baseScale.x * limbs[i]->scale.x,
				0.5f * limbs[i]->parent->baseScale.z * limbs[i]->parent->scale.z - 0.5f * limbs[i]->baseScale.z * limbs[i]->scale.z);
			break;
		case doggo::HEAD:
			tmpRotate.rotate(180.0f, X_AXIS);
			break;
		case doggo::MUZZLE:
			tmpTranslate.translate(-0.5f * limbs[i]->baseScale.x * limbs[i]->scale.x, -limbs[i]->parent->baseScale.y * limbs[i]->parent->scale.y, 0.0f);
			break;
		case doggo::RIGHT_EAR:
			tmpRotate.rotate(90.0f, Z_AXIS);
			tmpTranslate.translate(0.5f * limbs[i]->parent->baseScale.x * limbs[i]->parent->scale.x,
				-0.5f * limbs[i]->baseScale.x * limbs[i]->scale.x,
				0.5f * limbs[i]->parent->baseScale.z * limbs[i]->parent->scale.z - 0.5f * limbs[i]->baseScale.z * limbs[i]->scale.z);
			break;
		case doggo::LEFT_EAR:
			tmpRotate.rotate(90.0f, Z_AXIS);
			tmpTranslate.translate(0.5f * limbs[i]->parent->baseScale.x * limbs[i]->parent->scale.x,
				-0.5f * limbs[i]->baseScale.x * limbs[i]->scale.x,
				-0.5f * limbs[i]->parent->baseScale.z * limbs[i]->parent->scale.z + 0.5f * limbs[i]->baseScale.z * limbs[i]->scale.z);
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

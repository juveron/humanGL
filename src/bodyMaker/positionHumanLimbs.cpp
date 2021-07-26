#include "HumanGL.hpp"


void positionHumanLimbs(std::vector<Limb*> &limbs)
{
	size_t i = 0;
	Matrix4 tmp;
	while (i < limbs.size())
	{
		limbs[i]->currentMat = Matrix4::newIdentityMatrix();
		i++;
	}

	tmp = Matrix4::newIdentityMatrix();
	tmp.rotate(limbs[TORSO]->rotation.x, X_AXIS);
	tmp.rotate(limbs[TORSO]->rotation.y, Y_AXIS);
	tmp.rotate(limbs[TORSO]->rotation.z, Z_AXIS);
	tmp.translate(limbs[TORSO]->translation.x, limbs[TORSO]->translation.y, limbs[TORSO]->translation.z);
	limbs[TORSO]->currentMat = tmp;
	tmp = Matrix4::newIdentityMatrix();
	tmp.rotate(180.0f, X_AXIS);
	tmp.rotate(limbs[HEAD]->rotation.x, X_AXIS);
	tmp.rotate(limbs[HEAD]->rotation.y, Y_AXIS);
	tmp.rotate(limbs[HEAD]->rotation.z, Z_AXIS);
	tmp.translate(limbs[HEAD]->translation.x, limbs[HEAD]->translation.y, limbs[HEAD]->translation.z);
	limbs[HEAD]->currentMat = tmp;
	tmp = Matrix4::newIdentityMatrix();
	tmp.translate(0.5f * limbs[RIGHT_ARM]->scale.x + 0.5f * limbs[RIGHT_ARM]->parent->scale.x, 0.0f, 0.0f);
	tmp.rotate(limbs[RIGHT_ARM]->rotation.x, X_AXIS);
	tmp.rotate(limbs[RIGHT_ARM]->rotation.y, Y_AXIS);
	tmp.rotate(limbs[RIGHT_ARM]->rotation.z, Z_AXIS);
	tmp.translate(limbs[RIGHT_ARM]->translation.x, limbs[RIGHT_ARM]->translation.y, limbs[RIGHT_ARM]->translation.z);
	limbs[RIGHT_ARM]->currentMat *= tmp;
	tmp = Matrix4::newIdentityMatrix();
	tmp.translate(0.0f, -limbs[RIGHT_FOREARM]->parent->scale.y, 0.0f);
	tmp.rotate(limbs[RIGHT_FOREARM]->rotation.x, X_AXIS);
	tmp.rotate(limbs[RIGHT_FOREARM]->rotation.y, Y_AXIS);
	tmp.rotate(limbs[RIGHT_FOREARM]->rotation.z, Z_AXIS);
	tmp.translate(limbs[RIGHT_FOREARM]->translation.x, limbs[RIGHT_FOREARM]->translation.y, limbs[RIGHT_FOREARM]->translation.z);
	limbs[RIGHT_FOREARM]->currentMat *= tmp;
	tmp = Matrix4::newIdentityMatrix();
	tmp.translate(0.0f, -limbs[RIGHT_HAND]->parent->scale.y, 0.0f);
	tmp.rotate(limbs[RIGHT_HAND]->rotation.x, X_AXIS);
	tmp.rotate(limbs[RIGHT_HAND]->rotation.y, Y_AXIS);
	tmp.rotate(limbs[RIGHT_HAND]->rotation.z, Z_AXIS);
	tmp.translate(limbs[RIGHT_HAND]->translation.x, limbs[RIGHT_HAND]->translation.y, limbs[RIGHT_HAND]->translation.z);
	limbs[RIGHT_HAND]->currentMat *= tmp;
	tmp = Matrix4::newIdentityMatrix();
	tmp.translate(-(0.5f * limbs[LEFT_ARM]->scale.x + 0.5f * limbs[LEFT_ARM]->parent->scale.x), 0.0f, 0.0f);
	tmp.rotate(limbs[LEFT_ARM]->rotation.x, X_AXIS);
	tmp.rotate(limbs[LEFT_ARM]->rotation.y, Y_AXIS);
	tmp.rotate(limbs[LEFT_ARM]->rotation.z, Z_AXIS);
	tmp.translate(limbs[LEFT_ARM]->translation.x, limbs[LEFT_ARM]->translation.y, limbs[LEFT_ARM]->translation.z);
	limbs[LEFT_ARM]->currentMat *= tmp;
	tmp = Matrix4::newIdentityMatrix();
	tmp.translate(0.0f, -limbs[LEFT_FOREARM]->parent->scale.y, 0.0f);
	tmp.rotate(limbs[LEFT_FOREARM]->rotation.x, X_AXIS);
	tmp.rotate(limbs[LEFT_FOREARM]->rotation.y, Y_AXIS);
	tmp.rotate(limbs[LEFT_FOREARM]->rotation.z, Z_AXIS);
	tmp.translate(limbs[LEFT_FOREARM]->translation.x, limbs[LEFT_FOREARM]->translation.y, limbs[LEFT_FOREARM]->translation.z);
	limbs[LEFT_FOREARM]->currentMat *= tmp;
	tmp = Matrix4::newIdentityMatrix();
	tmp.translate(0.0f, -limbs[LEFT_HAND]->parent->scale.y, 0.0f);
	tmp.rotate(limbs[LEFT_HAND]->rotation.x, X_AXIS);
	tmp.rotate(limbs[LEFT_HAND]->rotation.y, Y_AXIS);
	tmp.rotate(limbs[LEFT_HAND]->rotation.z, Z_AXIS);
	tmp.translate(limbs[LEFT_HAND]->translation.x, limbs[LEFT_HAND]->translation.y, limbs[LEFT_HAND]->translation.z);
	limbs[LEFT_HAND]->currentMat *= tmp;
	tmp = Matrix4::newIdentityMatrix();
	tmp.translate(0.5f * limbs[RIGHT_THIGH]->scale.x, -limbs[RIGHT_THIGH]->parent->scale.y, 0.0f);
	tmp.rotate(limbs[RIGHT_THIGH]->rotation.x, X_AXIS);
	tmp.rotate(limbs[RIGHT_THIGH]->rotation.y, Y_AXIS);
	tmp.rotate(limbs[RIGHT_THIGH]->rotation.z, Z_AXIS);
	tmp.translate(limbs[RIGHT_THIGH]->translation.x, limbs[RIGHT_THIGH]->translation.y, limbs[RIGHT_THIGH]->translation.z);
	limbs[RIGHT_THIGH]->currentMat *= tmp;
	tmp = Matrix4::newIdentityMatrix();
	tmp.translate(0.0f, -limbs[RIGHT_LEG]->parent->scale.y, 0.0f);
	tmp.rotate(limbs[RIGHT_LEG]->rotation.x, X_AXIS);
	tmp.rotate(limbs[RIGHT_LEG]->rotation.y, Y_AXIS);
	tmp.rotate(limbs[RIGHT_LEG]->rotation.z, Z_AXIS);
	tmp.translate(limbs[RIGHT_LEG]->translation.x, limbs[RIGHT_LEG]->translation.y, limbs[RIGHT_LEG]->translation.z);
	limbs[RIGHT_LEG]->currentMat *= tmp;
	tmp = Matrix4::newIdentityMatrix();
	tmp.translate(0.0f, -limbs[RIGHT_FOOT]->parent->scale.y, 0.15f);
	tmp.rotate(limbs[RIGHT_FOOT]->rotation.x, X_AXIS);
	tmp.rotate(limbs[RIGHT_FOOT]->rotation.y, Y_AXIS);
	tmp.rotate(limbs[RIGHT_FOOT]->rotation.z, Z_AXIS);
	tmp.translate(limbs[RIGHT_FOOT]->translation.x, limbs[RIGHT_FOOT]->translation.y, limbs[RIGHT_FOOT]->translation.z);
	limbs[RIGHT_FOOT]->currentMat *= tmp;
	tmp = Matrix4::newIdentityMatrix();
	tmp.translate(-0.5f * limbs[LEFT_THIGH]->scale.x, -limbs[LEFT_THIGH]->parent->scale.y, 0.0f);
	tmp.rotate(limbs[LEFT_THIGH]->rotation.x, X_AXIS);
	tmp.rotate(limbs[LEFT_THIGH]->rotation.y, Y_AXIS);
	tmp.rotate(limbs[LEFT_THIGH]->rotation.z, Z_AXIS);
	tmp.translate(limbs[LEFT_THIGH]->translation.x, limbs[LEFT_THIGH]->translation.y, limbs[LEFT_THIGH]->translation.z);
	limbs[LEFT_THIGH]->currentMat *= tmp;
	tmp = Matrix4::newIdentityMatrix();
	tmp.translate(0.0f, -limbs[LEFT_LEG]->parent->scale.y, 0.0f);
	tmp.rotate(limbs[LEFT_LEG]->rotation.x, X_AXIS);
	tmp.rotate(limbs[LEFT_LEG]->rotation.y, Y_AXIS);
	tmp.rotate(limbs[LEFT_LEG]->rotation.z, Z_AXIS);
	tmp.translate(limbs[LEFT_LEG]->translation.x, limbs[LEFT_LEG]->translation.y, limbs[LEFT_LEG]->translation.z);
	limbs[LEFT_LEG]->currentMat *= tmp;
	tmp = Matrix4::newIdentityMatrix();
	tmp.translate(0.0f, -limbs[LEFT_FOOT]->parent->scale.y, 0.15f);
	tmp.rotate(limbs[LEFT_FOOT]->rotation.x, X_AXIS);
	tmp.rotate(limbs[LEFT_FOOT]->rotation.y, Y_AXIS);
	tmp.rotate(limbs[LEFT_FOOT]->rotation.z, Z_AXIS);
	tmp.translate(limbs[LEFT_FOOT]->translation.x, limbs[LEFT_FOOT]->translation.y, limbs[LEFT_FOOT]->translation.z);
	limbs[LEFT_FOOT]->currentMat *= tmp;

}

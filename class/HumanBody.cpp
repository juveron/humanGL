#include "HumanGL.hpp"

HumanBody::HumanBody(void) : ABody()
{
	this->generateLimbs();
	this->position();
}

HumanBody::HumanBody(HumanBody const &c) : ABody(c)
{
}

HumanBody::~HumanBody()
{
}

void HumanBody::generateLimbs(void)
{
	Limb *torso = new Limb();
	this->limbs.push_back(torso);
	torso->baseScale = Vector3f(1.0f, 1.5f, 0.5f);

	// Head
	Limb *head = new Limb(torso);
	this->limbs.push_back(head);
	head->baseScale = Vector3f(1.0f, 1.0f, 1.0f);
	head->baseRotation = Vector3f(180.0f, 0.0f, 0.0f);

	// Upper right side
	Limb *rightArm = new Limb(torso);
	this->limbs.push_back(rightArm);
	rightArm->baseScale = Vector3f(0.5f, 0.75f, 0.5f);
	Limb *rightForearm = new Limb(rightArm);
	this->limbs.push_back(rightForearm);
	rightForearm->baseScale = Vector3f(0.5f, 0.75f, 0.5f);

	// Upper left side
	Limb *leftArm = new Limb(torso);
	this->limbs.push_back(leftArm);
	leftArm->baseScale = Vector3f(0.5f, 0.75f, 0.5f);
	Limb *leftForearm = new Limb(leftArm);
	this->limbs.push_back(leftForearm);
	leftForearm->baseScale = Vector3f(0.5f, 0.75f, 0.5f);

	// Lower right side
	Limb *rightTigh = new Limb(torso);
	this->limbs.push_back(rightTigh);
	rightTigh->baseScale = Vector3f(0.5f, 0.75f, 0.5f);
	Limb *rightLeg = new Limb(rightTigh);
	this->limbs.push_back(rightLeg);
	rightLeg->baseScale = Vector3f(0.5f, 0.75f, 0.5f);

	// Lower left side
	Limb *leftTigh = new Limb(torso);
	this->limbs.push_back(leftTigh);
	leftTigh->baseScale = Vector3f(0.5f, 0.75f, 0.5f);
	Limb *leftLeg = new Limb(leftTigh);
	this->limbs.push_back(leftLeg);
	leftLeg->baseScale = Vector3f(0.5f, 0.75f, 0.5f);
}

void HumanBody::position(void)
{
	size_t i = 0;

	Matrix4 tmpRotate;
	Matrix4 tmpTranslate;
	Matrix4 tmpScale;

	while (i < this->limbs.size())
	{
		this->limbs[i]->rotateMat = Matrix4::newIdentityMatrix();
		this->limbs[i]->translateMat = Matrix4::newIdentityMatrix();
		this->limbs[i]->scaleMat = Matrix4::newIdentityMatrix();

		tmpRotate = Matrix4::newIdentityMatrix();
		tmpTranslate = Matrix4::newIdentityMatrix();
		tmpScale = Matrix4::newIdentityMatrix();

		switch (i)
		{
		case human::TORSO:
			break;
		case human::HEAD:
			break;
		case human::RIGHT_ARM:
			tmpTranslate.translate(0.5f * this->limbs[human::RIGHT_ARM]->baseScale.x + 0.5f * this->limbs[human::RIGHT_ARM]->parent->baseScale.x * this->limbs[human::RIGHT_ARM]->parent->scale.x, 0.0f, 0.0f);
			break;
		case human::RIGHT_FOREARM:
			tmpTranslate.translate(0.0f, -this->limbs[human::RIGHT_FOREARM]->parent->baseScale.y * this->limbs[human::RIGHT_FOREARM]->parent->scale.y, 0.0f);
			break;
		case human::LEFT_ARM:
			tmpTranslate.translate(-(0.5f * this->limbs[human::LEFT_ARM]->baseScale.x + 0.5f * this->limbs[human::LEFT_ARM]->parent->baseScale.x * this->limbs[human::LEFT_ARM]->parent->scale.x), 0.0f, 0.0f);
			break;
		case human::LEFT_FOREARM:
			tmpTranslate.translate(0.0f, -this->limbs[human::LEFT_FOREARM]->parent->baseScale.y * this->limbs[human::LEFT_FOREARM]->parent->scale.y, 0.0f);
			break;
		case human::RIGHT_THIGH:
			tmpTranslate.translate(0.5f * this->limbs[human::RIGHT_THIGH]->baseScale.x, -this->limbs[human::RIGHT_THIGH]->parent->baseScale.y * this->limbs[human::RIGHT_THIGH]->parent->scale.y, 0.0f);
			break;
		case human::RIGHT_LEG:
			tmpTranslate.translate(0.0f, -this->limbs[human::RIGHT_LEG]->parent->baseScale.y * this->limbs[human::RIGHT_LEG]->parent->scale.y, 0.0f);
			break;
		case human::LEFT_THIGH:
			tmpTranslate.translate(-0.5f * this->limbs[human::LEFT_THIGH]->baseScale.x, -this->limbs[human::LEFT_THIGH]->parent->baseScale.y * this->limbs[human::LEFT_THIGH]->parent->scale.y, 0.0f);
			break;
		case human::LEFT_LEG:
			tmpTranslate.translate(0.0f, -this->limbs[human::LEFT_LEG]->parent->baseScale.y * this->limbs[human::LEFT_LEG]->parent->scale.y, 0.0f);
			break;
		default:
			break;
		}
		tmpRotate.rotate(this->limbs[i]->baseRotation.x, X_AXIS);
		tmpRotate.rotate(this->limbs[i]->baseRotation.y, Y_AXIS);
		tmpRotate.rotate(this->limbs[i]->baseRotation.z, Z_AXIS);
		tmpRotate.rotate(this->limbs[i]->rotation.x, X_AXIS);
		tmpRotate.rotate(this->limbs[i]->rotation.y, Y_AXIS);
		tmpRotate.rotate(this->limbs[i]->rotation.z, Z_AXIS);
		this->limbs[i]->rotateMat = tmpRotate;

		tmpTranslate.translate(this->limbs[i]->translation.x, this->limbs[i]->translation.y, this->limbs[i]->translation.z);
		this->limbs[i]->translateMat = tmpTranslate;

		tmpScale.scale(this->limbs[i]->baseScale.x, this->limbs[i]->baseScale.y, this->limbs[i]->baseScale.z);
		tmpScale.scale(this->limbs[i]->scale.x, this->limbs[i]->scale.y, this->limbs[i]->scale.z);
		this->limbs[i]->scaleMat = tmpScale;

		i++;
	}
}

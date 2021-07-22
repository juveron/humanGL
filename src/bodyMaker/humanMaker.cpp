#include "../../hdr/HumanGL.hpp"

s_body humanMaker(void)
{
	s_body human;
	Limb *torso = new Limb();
	human.limb = torso;
	human.limbs.push_back(torso);
	torso->scaleLimb(1.0f, 2.0f, 1.0f);

	// Head
	Limb *head = new Limb(torso);
	human.limbs.push_back(head);
	head->scaleLimb(0.75f);
	head->rotateLimb(180, Z_AXIS);

	// Upper right side
	Limb *rightArm = new Limb(torso);
	human.limbs.push_back(rightArm);
	rightArm->scaleLimb(0.5f, 1.0f, 0.75f);
	rightArm->translateLimb(0.5f * rightArm->scale.x + 0.5f * rightArm->parent->scale.x, 0.0f, 0.0f);
	Limb *rightForearm = new Limb(rightArm);
	human.limbs.push_back(rightForearm);
	rightForearm->scaleLimb(0.40f, 0.9f, 0.5f);
	rightForearm->translateLimb(0.0f, -rightForearm->parent->scale.y, 0.0f);
	Limb *rightHand = new Limb(rightForearm);
	human.limbs.push_back(rightHand);
	rightHand->scaleLimb(0.25f, 0.25f, 0.25f);
	rightHand->translateLimb(0.0f, -rightHand->parent->scale.y, 0.0f);

	// Upper left side
	Limb *leftArm = new Limb(torso);
	human.limbs.push_back(leftArm);
	leftArm->scaleLimb(0.5f, 1.0f, 0.75f);
	leftArm->translateLimb(-(0.5f * leftArm->scale.x + 0.5f * leftArm->parent->scale.x), 0.0f, 0.0f);
	Limb *leftForearm = new Limb(leftArm);
	human.limbs.push_back(leftForearm);
	leftForearm->scaleLimb(0.40f, 0.9f, 0.5f);
	leftForearm->translateLimb(0.0f, -leftForearm->parent->scale.y, 0.0f);
	Limb *leftHand = new Limb(leftForearm);
	human.limbs.push_back(leftHand);
	leftHand->scaleLimb(0.25f, 0.25f, 0.25f);
	leftHand->translateLimb(0.0f, -leftHand->parent->scale.y, 0.0f);

	// Lower right side
	Limb *rightTigh = new Limb(torso);
	human.limbs.push_back(rightTigh);
	rightTigh->scaleLimb(0.5f, 1.2f, 0.5f);
	rightTigh->translateLimb(0.5f * rightTigh->scale.x, -rightTigh->parent->scale.y, 0.0f);
	Limb *rightLeg = new Limb(rightTigh);
	human.limbs.push_back(rightLeg);
	rightLeg->scaleLimb(0.4f, 0.9f, 0.5f);
	rightLeg->translateLimb(0.0f, -rightLeg->parent->scale.y, 0.0f);
	Limb *rightFoot = new Limb(rightLeg);
	human.limbs.push_back(rightFoot);
	rightFoot->scaleLimb(0.3f, 0.3f, 0.75f);
	rightFoot->translateLimb(0.0f, -rightFoot->parent->scale.y, 0.15f);

	// Lower left side
	Limb *leftTigh = new Limb(torso);
	human.limbs.push_back(leftTigh);
	leftTigh->scaleLimb(0.5f, 1.2f, 0.5f);
	leftTigh->translateLimb(-0.5f * leftTigh->scale.x, -leftTigh->parent->scale.y, 0.0f);
	Limb *leftLeg = new Limb(leftTigh);
	human.limbs.push_back(leftLeg);
	leftLeg->scaleLimb(0.4f, 0.9f, 0.5f);
	leftLeg->translateLimb(0.0f, -leftLeg->parent->scale.y, 0.0f);
	Limb *leftFoot = new Limb(leftLeg);
	human.limbs.push_back(leftFoot);
	leftFoot->scaleLimb(0.3f, 0.3f, 0.75f);
	leftFoot->translateLimb(0.0f, -leftFoot->parent->scale.y, 0.15f);


	return human;
}

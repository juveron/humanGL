#include "HumanGL.hpp"

s_body humanMaker(void)
{
	s_body human;
	human.selectedLimb = 0;
	Limb *torso = new Limb();
	human.limb = torso;
	human.limbs.push_back(torso);
	torso->scaleLimb(1.0f, 2.0f, 1.0f);

	// Head
	Limb *head = new Limb(torso);
	human.limbs.push_back(head);
	head->scaleLimb(0.75f);
	head->rotateLimb(180, X_AXIS);

	// Upper right side
	Limb *rightArm = new Limb(torso);
	human.limbs.push_back(rightArm);
	rightArm->scaleLimb(0.5f, 1.0f, 0.75f);
	Limb *rightForearm = new Limb(rightArm);
	human.limbs.push_back(rightForearm);
	rightForearm->scaleLimb(0.40f, 0.9f, 0.5f);
	Limb *rightHand = new Limb(rightForearm);
	human.limbs.push_back(rightHand);
	rightHand->scaleLimb(0.25f, 0.25f, 0.25f);

	// Upper left side
	Limb *leftArm = new Limb(torso);
	human.limbs.push_back(leftArm);
	leftArm->scaleLimb(0.5f, 1.0f, 0.75f);
	Limb *leftForearm = new Limb(leftArm);
	human.limbs.push_back(leftForearm);
	leftForearm->scaleLimb(0.40f, 0.9f, 0.5f);
	Limb *leftHand = new Limb(leftForearm);
	human.limbs.push_back(leftHand);
	leftHand->scaleLimb(0.25f, 0.25f, 0.25f);

	// Lower right side
	Limb *rightTigh = new Limb(torso);
	human.limbs.push_back(rightTigh);
	rightTigh->scaleLimb(0.5f, 1.2f, 0.5f);
	Limb *rightLeg = new Limb(rightTigh);
	human.limbs.push_back(rightLeg);
	rightLeg->scaleLimb(0.4f, 0.9f, 0.5f);
	Limb *rightFoot = new Limb(rightLeg);
	human.limbs.push_back(rightFoot);
	rightFoot->scaleLimb(0.3f, 0.3f, 0.75f);

	// Lower left side
	Limb *leftTigh = new Limb(torso);
	human.limbs.push_back(leftTigh);
	leftTigh->scaleLimb(0.5f, 1.2f, 0.5f);
	Limb *leftLeg = new Limb(leftTigh);
	human.limbs.push_back(leftLeg);
	leftLeg->scaleLimb(0.4f, 0.9f, 0.5f);
	Limb *leftFoot = new Limb(leftLeg);
	human.limbs.push_back(leftFoot);
	leftFoot->scaleLimb(0.3f, 0.3f, 0.75f);

	positionHumanLimbs(human.limbs);

	return human;
}

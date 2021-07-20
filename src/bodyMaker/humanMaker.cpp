#include "../../hdr/HumanGL.hpp"

Limb *humanMaker(void)
{
	Limb *torso = new Limb();
	torso->scaleMat.scale(1.0f, 2.0f, 1.0f);

	// Head
	Limb *head = new Limb(torso);
	head->scaleMat.scale(2.0f);
	head->currentMat.rotate(180, Z_AXIS);

	// Upper right side
	Limb *rightArm = new Limb(torso);
	rightArm->scaleMat.scale(0.5f, 1.0f, 0.75f);
	rightArm->currentMat.translate(0.75f, 0.0f, 0.0f);
	Limb *rightForearm = new Limb(rightArm);
	rightForearm->scaleMat.scale(0.40f, 0.9f, 0.5f);
	rightForearm->currentMat.translate(0.0f, -1.0f, 0.0f);
	Limb *rightHand = new Limb(rightForearm);
	rightHand->scaleMat.scale(0.25f, 0.25f, 0.25f);
	rightHand->currentMat.translate(0.0f, -0.9f, 0.0f);

	// Upper left side
	Limb *leftArm = new Limb(torso);
	leftArm->scaleMat.scale(0.5f, 3.0f, 0.75f);
	leftArm->currentMat.translate(-0.75f, 0.0f, 0.0f);
	Limb *leftForearm = new Limb(leftArm);
	leftForearm->scaleMat.scale(0.40f, 0.9f, 0.5f);
	leftForearm->currentMat.translate(0.0f, -1.0f, 0.0f);
	Limb *leftHand = new Limb(leftForearm);
	leftHand->scaleMat.scale(0.25f, 0.25f, 0.25f);
	leftHand->currentMat.translate(0.0f, -0.9f, 0.0f);

	// Lower right side
	Limb *rightTigh = new Limb(torso);
	rightTigh->scaleMat.scale(0.5f, 1.2f, 0.5f);
	rightTigh->currentMat.translate(0.25f, -2.0f, 0.0f);
	Limb *rightLeg = new Limb(rightTigh);
	rightLeg->scaleMat.scale(0.4f, 0.9f, 0.5f);
	rightLeg->currentMat.translate(0.0f, -1.2f, 0.0f);
	Limb *rightFoot = new Limb(rightLeg);
	rightFoot->scaleMat.scale(0.3f, 0.3f, 0.75f);
	rightFoot->currentMat.translate(0.0f, -0.9f, 0.15f);

	// Lower left side
	Limb *leftTigh = new Limb(torso);
	leftTigh->scaleMat.scale(0.5f, 1.2f, 0.5f);
	leftTigh->currentMat.translate(-0.25f, -2.0f, 0.0f);
	Limb *leftLeg = new Limb(leftTigh);
	leftLeg->scaleMat.scale(0.4f, 0.9f, 0.5f);
	leftLeg->currentMat.translate(0.0f, -1.2f, 0.0f);
	Limb *leftFoot = new Limb(leftLeg);
	leftFoot->scaleMat.scale(0.3f, 0.3f, 0.75f);
	leftFoot->currentMat.translate(0.0f, -0.9f, 0.15f);


	return torso;
}

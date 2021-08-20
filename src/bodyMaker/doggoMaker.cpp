#include "HumanGL.hpp"

s_body doggoMaker(void)
{
	s_body doggo;
	doggo.selectedLimb = 0;

	Limb *torso = new Limb();
	doggo.limb = torso;
	doggo.limbs.push_back(torso);
	torso->baseScale = Vector3f(0.875f, 1.0f, 0.75f);

	// Low Torso
	Limb *lowTorso = new Limb(torso);
	doggo.limb = lowTorso;
	doggo.limbs.push_back(lowTorso);
	lowTorso->baseScale = Vector3f(0.75f, 0.75f, 1.125f);

	// Head
	Limb *head = new Limb(torso);
	doggo.limbs.push_back(head);
	head->baseScale = Vector3f(0.75f, 0.75f, 0,375f);
	head->baseRotation = Vector3f(180.0f, 0.0f, 0.0f);

	// Muzzle
	Limb *muzzle = new Limb(head);
	doggo.limbs.push_back(muzzle);
	muzzle->baseScale = Vector3f(0,375f, 0,375f, 0,375f);

	// right ear
	Limb *rightEar = new Limb(head);
	doggo.limbs.push_back(rightEar);
	rightEar->baseScale = Vector3f(0,25f, 0,25f, 0,25f);

	// left ear
	Limb *leftEar = new Limb(head);
	doggo.limbs.push_back(leftEar);
	leftEar->baseScale = Vector3f(0,25f, 0,25f, 0,25f);

	// tail
	Limb *tail = new Limb(lowTorso);
	doggo.limbs.push_back(tail);
	tail->baseScale = Vector3f(0.25f, 0.25f, 1.0f);

	// Upper right side
	Limb *rightPaw = new Limb(torso);
	doggo.limbs.push_back(rightPaw);
	rightPaw->baseScale = Vector3f(1.0f, 0.25f, 0.25f);

//	Limb *rightForearm = new Limb(rightArm);
//	doggo.limbs.push_back(rightForearm);
//	rightForearm->baseScale = Vector3f(0.5f, 0.75f, 0.5f);
	// Limb *rightHand = new Limb(rightForearm);
	// human.limbs.push_back(rightHand);
	// rightHand->baseScale = Vector3f(0.25f, 0.25f, 0.25f);

	// Upper left side
	Limb *leftPaw = new Limb(torso);
	doggo.limbs.push_back(leftPaw);
	leftPaw->baseScale = Vector3f(1.0f, 0.25f, 0.25f);

//	Limb *leftForearm = new Limb(leftArm);
//	doggo.limbs.push_back(leftForearm);
//	leftForearm->baseScale = Vector3f(0.5f, 0.75f, 0.5f);
	// Limb *leftHand = new Limb(leftForearm);
	// human.limbs.push_back(leftHand);
	// leftHand->baseScale = Vector3f(0.25f, 0.25f, 0.25f);

	// Lower right side
	Limb *lowerRightPaw = new Limb(lowTorso);
	doggo.limbs.push_back(lowerRightPaw);
	lowerRightPaw->baseScale = Vector3f(1.0f, 0.25f, 0.25f);

//	Limb *rightLeg = new Limb(rightTigh);
//	doggo.limbs.push_back(rightLeg);
//	rightLeg->baseScale = Vector3f(0.5f, 0.75f, 0.5f);
	// Limb *rightFoot = new Limb(rightLeg);
	// human.limbs.push_back(rightFoot);
	// rightFoot->baseScale = Vector3f(0.3f, 0.3f, 0.75f);

	// Lower left side
	Limb *lowerLeftPaw = new Limb(lowTorso);
	doggo.limbs.push_back(lowerLeftPaw);
	lowerLeftPaw->baseScale = Vector3f(1.0f, 0.25f, 0.25f);

//	Limb *leftLeg = new Limb(leftTigh);
//	doggo.limbs.push_back(leftLeg);
//	leftLeg->baseScale = Vector3f(0.5f, 0.75f, 0.5f);
	// Limb *leftFoot = new Limb(leftLeg);
	// human.limbs.push_back(leftFoot);
	// leftFoot->baseScale = Vector3f(0.3f, 0.3f, 0.75f);

	positionHumanLimbs(doggo.limbs);

	return doggo;
}

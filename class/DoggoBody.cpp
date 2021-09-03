#include "HumanGL.hpp"

DoggoBody::DoggoBody(void) : ABody()
{
	this->generateLimbs();
	this->position();
}

DoggoBody::DoggoBody(int bodyIndex_) : ABody(bodyIndex_)
{
	this->generateLimbs();
	this->position();
}

DoggoBody::DoggoBody(DoggoBody const &c) : ABody(c)
{
}

DoggoBody::~DoggoBody(void)
{
}

void DoggoBody::generateLimbs(void)
{
	this->selectedLimb = 0;

	Limb *torso = new Limb();
	this->limb = torso;
	this->limbs.push_back(torso);
	torso->baseScale = Vector3f(0.875f, 0.75f, 1.0f);
	torso->baseRotation = Vector3f(0.0f, 0.0f, 90.0f);

	// Low Torso
	Limb *lowTorso = new Limb(torso);
	this->limbs.push_back(lowTorso);
	lowTorso->baseScale = Vector3f(0.75f, 1.125f, 0.75f);

	// Tail
	Limb *tail = new Limb(lowTorso);
	this->limbs.push_back(tail);
	tail->baseScale = Vector3f(0.25f, 1.0f, 0.25f);

	// Lower right side
	Limb *lowerRightPaw = new Limb(lowTorso);
	this->limbs.push_back(lowerRightPaw);
	lowerRightPaw->baseScale = Vector3f(0.25f, 0.75f, 0.25f);
	lowerRightPaw->baseRotation = Vector3f(0.0f, 0.0f, -90.0f);


	// Lower left side
	Limb *lowerLeftPaw = new Limb(lowTorso);
	this->limbs.push_back(lowerLeftPaw);
	lowerLeftPaw->baseScale = Vector3f(0.25f, 0.75f, 0.25f);
	lowerLeftPaw->baseRotation = Vector3f(0.0f, 0.0f, -90.0f);


	// Upper right side
	Limb *rightPaw = new Limb(torso);
	this->limbs.push_back(rightPaw);
	rightPaw->baseScale = Vector3f(0.25f, 0.75f, 0.25f);
	rightPaw->baseRotation = Vector3f(0.0f, 0.0f, -90.0f);


	// Upper left side
	Limb *leftPaw = new Limb(torso);
	this->limbs.push_back(leftPaw);
	leftPaw->baseScale = Vector3f(0.25f, 0.75f, 0.25f);
	leftPaw->baseRotation = Vector3f(0.0f, 0.0f, -90.0f);


	// Head
	Limb *head = new Limb(torso);
	this->limbs.push_back(head);
	head->baseScale = Vector3f(0.75f, 0.375f, 0.75);
	head->baseRotation = Vector3f(180.0f, 0.0f, 0.0f);

	// Muzzle
	Limb *muzzle = new Limb(head);
	this->limbs.push_back(muzzle);
	muzzle->baseScale = Vector3f(0.375f, 0.375f, 0.375f);

	// right ear
	Limb *rightEar = new Limb(head);
	this->limbs.push_back(rightEar);
	rightEar->baseScale = Vector3f(0.125f, 0.25f, 0.25f);

	// left ear
	Limb *leftEar = new Limb(head);
	this->limbs.push_back(leftEar);
	leftEar->baseScale = Vector3f(0.125f, 0.25f, 0.25f);
}

void DoggoBody::position(void)
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
		case doggo::TORSO:
			tmpRotate.rotate(90.0f, Z_AXIS);
			break;
		case doggo::LOW_TORSO:
			tmpTranslate.translate(-0.5f * (this->limbs[i]->parent->baseScale.x * this->limbs[i]->parent->scale.x - this->limbs[i]->baseScale.x * this->limbs[i]->scale.x),
				-this->limbs[i]->parent->baseScale.y * this->limbs[i]->parent->scale.y, 0.0f);
			break;
		case doggo::TAIL:
			tmpTranslate.translate(0.5f * this->limbs[i]->parent->baseScale.x * this->limbs[i]->parent->scale.x - 0.5f * this->limbs[i]->baseScale.x * this->limbs[i]->scale.x,
				-this->limbs[i]->parent->baseScale.y * this->limbs[i]->parent->scale.y, 0.0f);
			break;
		case doggo::RIGHT_LOW_PAW:
			tmpRotate.rotate(-90.0f, Z_AXIS);
			tmpTranslate.translate(
				-0.5f * this->limbs[i]->parent->baseScale.x * this->limbs[i]->parent->scale.x,
				-0.9f * this->limbs[i]->parent->baseScale.y * this->limbs[i]->parent->scale.y + 0.5f * this->limbs[i]->baseScale.x * this->limbs[i]->scale.x,
				-(0.5f * this->limbs[i]->parent->baseScale.z * this->limbs[i]->parent->scale.z - 0.5f * this->limbs[i]->baseScale.z * this->limbs[i]->scale.z));
			break;
		case doggo::LEFT_LOW_PAW:
			tmpRotate.rotate(-90.0f, Z_AXIS);
			tmpTranslate.translate(-0.5f * this->limbs[i]->parent->baseScale.x * this->limbs[i]->parent->scale.x,
				-0.9f * this->limbs[i]->parent->baseScale.y * this->limbs[i]->parent->scale.y + 0.5f * this->limbs[i]->baseScale.x * this->limbs[i]->scale.x,
				0.5f * this->limbs[i]->parent->baseScale.z * this->limbs[i]->parent->scale.z - 0.5f * this->limbs[i]->baseScale.z * this->limbs[i]->scale.z);
			break;
		case doggo::RIGHT_UPPER_PAW:
			tmpRotate.rotate(-90.0f, Z_AXIS);
			tmpTranslate.translate(-0.5f * this->limbs[i]->parent->baseScale.x * this->limbs[i]->parent->scale.x,
				-0.3f * this->limbs[i]->parent->baseScale.y * this->limbs[i]->parent->scale.y - 0.5f * this->limbs[i]->baseScale.x * this->limbs[i]->scale.x,
				-(0.5f * this->limbs[i]->parent->baseScale.z * this->limbs[i]->parent->scale.z - 0.5f * this->limbs[i]->baseScale.z * this->limbs[i]->scale.z));
			break;
		case doggo::LEFT_UPPER_PAW:
			tmpRotate.rotate(-90.0f, Z_AXIS);
			tmpTranslate.translate(-0.5f * this->limbs[i]->parent->baseScale.x * this->limbs[i]->parent->scale.x,
				-0.3f * this->limbs[i]->parent->baseScale.y * this->limbs[i]->parent->scale.y - 0.5f * this->limbs[i]->baseScale.x * this->limbs[i]->scale.x,
				0.5f * this->limbs[i]->parent->baseScale.z * this->limbs[i]->parent->scale.z - 0.5f * this->limbs[i]->baseScale.z * this->limbs[i]->scale.z);
			break;
		case doggo::HEAD:
			tmpRotate.rotate(180.0f, X_AXIS);
			break;
		case doggo::MUZZLE:
			tmpTranslate.translate(-0.5f * this->limbs[i]->baseScale.x * this->limbs[i]->scale.x, -this->limbs[i]->parent->baseScale.y * this->limbs[i]->parent->scale.y, 0.0f);
			break;
		case doggo::RIGHT_EAR:
			tmpRotate.rotate(90.0f, Z_AXIS);
			tmpTranslate.translate(0.5f * this->limbs[i]->parent->baseScale.x * this->limbs[i]->parent->scale.x,
				-0.5f * this->limbs[i]->baseScale.x * this->limbs[i]->scale.x,
				0.5f * this->limbs[i]->parent->baseScale.z * this->limbs[i]->parent->scale.z - 0.5f * this->limbs[i]->baseScale.z * this->limbs[i]->scale.z);
			break;
		case doggo::LEFT_EAR:
			tmpRotate.rotate(90.0f, Z_AXIS);
			tmpTranslate.translate(0.5f * this->limbs[i]->parent->baseScale.x * this->limbs[i]->parent->scale.x,
				-0.5f * this->limbs[i]->baseScale.x * this->limbs[i]->scale.x,
				-0.5f * this->limbs[i]->parent->baseScale.z * this->limbs[i]->parent->scale.z + 0.5f * this->limbs[i]->baseScale.z * this->limbs[i]->scale.z);
			break;
		default:
			break;
		}

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

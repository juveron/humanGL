#include "../hdr/HumanGL.hpp"

Limb::Limb(void) : parent(nullptr)
{
	this->scale = Vector3f(1.0f, 1.0f, 1.0f);
}

Limb::Limb(Limb *parent_) : parent(parent_)
{
	parent_->addChild(this);
	this->scale = Vector3f(1.0f, 1.0f, 1.0f);
}

Limb::~Limb(void)
{
}

void Limb::rotateLimb(float const angle, e_axis const axis)
{
	if (axis == X_AXIS)
		this->rotation.x += angle;
	if (axis == Y_AXIS)
		this->rotation.y += angle;
	if (axis == Z_AXIS)
		this->rotation.z += angle;

	this->rotateMat = Matrix4::newIdentityMatrix();
	// Rotate X_AXIS
	this->rotateMat.rotate(this->_baseRotation.x, X_AXIS);
	this->rotateMat.rotate(this->rotation.x, X_AXIS);

	// Rotate Y_AXIS
	this->rotateMat.rotate(this->_baseRotation.y, Y_AXIS);
	this->rotateMat.rotate(this->rotation.y, Y_AXIS);

	// Rotate z_AXIS
	this->rotateMat.rotate(this->_baseRotation.z, Z_AXIS);
	this->rotateMat.rotate(this->rotation.z, Z_AXIS);
}

void Limb::translateLimb(float const x, float const y, float const z)
{
	this->translation.x += x;
	this->translation.y += y;
	this->translation.z += z;
	this->translateMat.translate(x, y, z);
}

void Limb::translateLimb(float const xyz)
{
	this->translation.x += xyz;
	this->translation.y += xyz;
	this->translation.z += xyz;
	this->translateMat.translate(xyz);
}

void Limb::scaleLimb(float const x, float const y, float const z)
{
	this->scale.x *= x;
	this->scale.y *= y;
	this->scale.z *= z;
	this->scaleMat.scale(x, y, z);
}

void Limb::scaleLimb(float const xyz)
{
	this->scale.x *= xyz;
	this->scale.y *= xyz;
	this->scale.z *= xyz;
	this->scaleMat.scale(xyz);
}

void Limb::addChild(Limb *child)
{
	this->children.push_back(child);
}

void Limb::removeChild(Limb *child)
{
	std::vector<Limb *>::iterator iter = this->children.begin();
	std::vector<Limb *>::iterator iterEnd = this->children.end();

	while (iter != iterEnd)
	{
		if (*iter == child)
		{
			this->children.erase(iter);
			break;
		}
		iter++;
	}
}

void Limb::setParent(Limb *parent)
{
	this->parent = parent;
}

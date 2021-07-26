#include "../hdr/HumanGL.hpp"

Limb::Limb(void) : scaleMat(), currentMat(), parent(nullptr), children()
{
	this->scale = Vector3f(1.0f, 1.0f, 1.0f);
}

Limb::Limb(Limb *parent_) : scaleMat(), currentMat(), parent(parent_), children()
{
	parent_->addChild(this);
	this->scale = Vector3f(1.0f, 1.0f, 1.0f);
}

Limb::~Limb(void)
{
}

void Limb::rotateLimb(float const angle, e_axis const axis)
{
	Matrix4 tmp = this->currentMat;
	this->currentMat = Matrix4::newIdentityMatrix();
	this->currentMat.rotate(angle, axis);
	this->currentMat *= tmp;
}

void Limb::translateLimb(float const x, float const y, float const z)
{
	this->currentMat.translate(x, y, z);
}

void Limb::translateLimb(float const xyz)
{
	this->currentMat.translate(xyz);
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

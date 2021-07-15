#include "../hdr/HumanGL.hpp"

Limb::Limb(void) : scaleMat(), currentMat(), parent(nullptr), children()
{
}

Limb::Limb(Limb *parent_) : scaleMat(), currentMat(), parent(parent_), children()
{
	parent_->addChild(this);
}

Limb::~Limb(void)
{
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

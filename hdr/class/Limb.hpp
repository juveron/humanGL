#ifndef LIMB_HPP
#define LIMB_HPP

#include "../HumanGL.hpp"

class Limb {
private:

public:
	Matrix4  scaleMat;
	Matrix4  currentMat;
	Limb *parent;
	std::vector<Limb *>children;
	void    addChild(Limb *child);
	void    setParent(Limb *parent);

};


#endif

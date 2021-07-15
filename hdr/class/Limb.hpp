#ifndef LIMB_HPP
#define LIMB_HPP

#include "../HumanGL.hpp"

class Limb {
private:

public:
	Limb(void);
	Limb(Limb *parent_);
	Limb(Limb const &c) = delete;
	~Limb(void);

	Matrix4				scaleMat;
	Matrix4				currentMat;
	Limb				*parent;
	std::vector<Limb *>	children;

	void	addChild(Limb *child);
	void	removeChild(Limb *child);

	void	setParent(Limb *parent);

	Limb &operator=(Limb const &rhs) = delete;
};

#endif

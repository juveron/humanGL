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

	Vector3f			scale;
	Vector3f			rotation;
	Vector3f			translation;

	Matrix4				scaleMat;
	Matrix4				currentMat;

	Limb				*parent;
	std::vector<Limb *>	children;

	void	rotateLimb(float const angle, e_axis const axis);
	void	translateLimb(float const x, float const y, float const z);
	void	translateLimb(float const xyz);
	void	scaleLimb(float const x, float const y, float const z);
	void	scaleLimb(float const xyz);

	void	addChild(Limb * child);
	void	removeChild(Limb *child);

	void	setParent(Limb *parent);

	Limb &operator=(Limb const &rhs) = delete;
};

#endif

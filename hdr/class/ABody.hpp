#ifndef ABODY_HPP
#define ABODY_HPP

#include "HumanGL.hpp"

class ABody
{
protected:
	unsigned int *_textures;
	Limb *limb;
	MatrixStack _stack;

	virtual void generateLimbs(void) = 0;

public:
	std::vector<Limb *> limbs;
	int selectedLimb;
	int bodyIndex;

	ABody(int bodyIndex_);
	ABody(ABody const &c);
	ABody(void);
	virtual ~ABody(void) {};

	int getSelectedLimb(void) const;
	std::vector<Limb *> getLimbs(void) const;

	unsigned int *getTextures(void) const;
	void setTextures(unsigned int *textures_);

	void draw(Shader &shader);
	void printToTerm(void);
	void printToFile(std::string const fileName);

	void update(ANIMATION_FRAME frame);
	void animate(Animation &animation, s_animationData &animationData);

	void resetBody(void);
	void resetSelectedLimb(void);

	virtual void position(void) = 0;

	ABody &operator=(ABody const &rhs);
};

#endif

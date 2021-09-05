#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include "HumanGL.hpp"

class Animation
{
private:
	float _duration;
	float _progress;
	std::vector<ANIMATION_FRAME> _anim;

public:

	Animation(float duration_, std::vector<ANIMATION_FRAME> anim_);
	Animation(Animation const &c);
	~Animation(void);

	float getDuration(void) const;
	float getProgress(void) const;
	std::vector<ANIMATION_FRAME> getAnimation(void) const;
	ANIMATION_FRAME getAnimationFrame(unsigned int index) const;

	void resetProgress(void);
	void incrementProgress(float inc);

	Animation &operator=(Animation const &rhs);
};


#endif

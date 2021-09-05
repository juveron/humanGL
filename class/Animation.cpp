#include "HumanGL.hpp"

Animation::Animation(float duration_, std::vector<ANIMATION_FRAME> anim_) : _duration(duration_), _progress(0), _anim(anim_)
{
}

Animation::Animation(Animation const &c) : _duration(c.getDuration()), _progress(c.getProgress()), _anim(c.getAnimation())
{
}

Animation::~Animation(void)
{
}

float Animation::getDuration(void) const
{
	return this->_duration;
}

float Animation::getProgress(void) const
{
	return this->_progress;
}

std::vector<ANIMATION_FRAME> Animation::getAnimation(void) const
{
	return this->_anim;
}

ANIMATION_FRAME Animation::getAnimationFrame(unsigned int index) const
{
	if (index < this->_anim.size())
		return this->_anim[index];
	return ANIMATION_FRAME();
}

void Animation::resetProgress(void)
{
	this->_progress = 0;
}

void Animation::incrementProgress(float inc)
{
	this->_progress += inc;
}

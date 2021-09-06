#include "HumanGL.hpp"

ABody::ABody(int bodyIndex_) : _textures(nullptr), _stack(), selectedLimb(0), bodyIndex(bodyIndex_)
{
	this->_stack.pushMatrix();
}

ABody::ABody(ABody const &c) : _textures(c.getTextures()), _stack(), selectedLimb(c.getSelectedLimb()), bodyIndex(c.bodyIndex)
{
	this->_stack.pushMatrix();
}

ABody::ABody(void) : _textures(nullptr), _stack(), selectedLimb(0), bodyIndex(0)
{
	this->_stack.pushMatrix();
}

int ABody::getSelectedLimb(void) const
{
	return this->selectedLimb;
}

std::vector<Limb *> ABody::getLimbs(void) const
{
	return this->limbs;
}

unsigned int *ABody::getTextures(void) const
{
	return this->_textures;
}

void ABody::setTextures(unsigned int *textures_)
{
	this->_textures = textures_;
	return;
}

void ABody::draw(Shader &shader)
{
	int index = 0;
	this->limbs[0]->draw(index, this->selectedLimb, this->_stack, shader, this->_textures);
}

void ABody::printToTerm(void)
{
	int i = 0;
	std::vector<Limb *>::iterator iter = this->limbs.begin();
	std::vector<Limb *>::iterator iterEnd = this->limbs.end();

	while (iter != iterEnd)
	{
		std::cout << "=============\nIndex " << i << ":\n-> Rotate Mat:" << std::endl;
		(*iter)->rotateMat.print();
		std::cout << "-> Translate Mat:" << std::endl;
		(*iter)->translateMat.print();
		std::cout << "-> Scale Mat:" << std::endl;
		(*iter)->scaleMat.print();
		i++;
		iter++;
	}
}

void ABody::printToFile(std::string const fileName)
{
	std::ofstream file;

	file.exceptions(std::ofstream::failbit | std::ofstream::badbit);

	try {
		file.open(fileName);
		std::vector<Limb *>::iterator iter = this->limbs.begin();
		std::vector<Limb *>::iterator iterEnd = this->limbs.end();
		file << "{" << std::endl;
		while (iter != iterEnd)
		{
			file << "\t{ Vector3f(" << (*iter)->rotation.x << "," << (*iter)->rotation.y << "," << (*iter)->rotation.z << "),";
			file << " Vector3f(" << (*iter)->translation.x << "," << (*iter)->translation.y << "," << (*iter)->translation.z << "),";
			file << " Vector3f(" << (*iter)->scale.x << "," << (*iter)->scale.y << "," << (*iter)->scale.z << ") }," << std::endl;

			iter++;
		}
		file << "}," << std::endl;
		file.close();
	}
	catch (std::exception &e) {
		ErrorHandler::setError("PRINT_FILE", e.what());
	}
}

void ABody::update(ANIMATION_FRAME frame)
{
	size_t i = 0;
	std::vector<Limb*> limbs = this->limbs;
	size_t size = limbs.size();

	while (i < size)
	{
		limbs[i]->rotation.x = frame[i][0].x;
		limbs[i]->rotation.y = frame[i][0].y;
		limbs[i]->rotation.z = frame[i][0].z;
		limbs[i]->translation.x = frame[i][1].x;
		limbs[i]->translation.y = frame[i][1].y;
		limbs[i]->translation.z = frame[i][1].z;
		limbs[i]->scale.x = frame[i][2].x;
		limbs[i]->scale.y = frame[i][2].y;
		limbs[i]->scale.z = frame[i][2].z;
		i++;
	}
	this->position();
}

void ABody::animate(Animation &animation, s_animationData &animationData)
{
	std::vector<ANIMATION_FRAME> anim = animation.getAnimation();
	float duration = animation.getDuration();
	float progress = animation.getProgress();
	ANIMATION_FRAME currentFrameData;

	float timePerFrame = duration / (anim.size() - 1);

	float realCurrentFrame = progress / timePerFrame;
	float prevFrameIndex = std::floor(realCurrentFrame);
	float nextFrameIndex = std::ceil(realCurrentFrame);
	float framePercentage = std::fmod(realCurrentFrame, 1);

	ANIMATION_FRAME prevFrame = animation.getAnimationFrame(prevFrameIndex);
	ANIMATION_FRAME nextFrame = animation.getAnimationFrame(nextFrameIndex);
	size_t i = 0;
	if (nextFrameIndex < anim.size()) {
		Vector3f rotation;
		Vector3f translation;
		Vector3f scale;

		while (i < prevFrame.size())
		{

			rotation = lerp(prevFrame[i][0], nextFrame[i][0], framePercentage);
			translation = lerp(prevFrame[i][1], nextFrame[i][1], framePercentage);
			scale = lerp(prevFrame[i][2], nextFrame[i][2], framePercentage);
			currentFrameData.push_back({ rotation, translation, scale });
			i++;
		}
		this->update(currentFrameData);
	}
	else {
		if (!animationData.isLoop)
			animationData.isAnimated = false;
		animation.resetProgress();
	}
}

void ABody::resetBody(void)
{
	size_t i = 0;
	while (i < this->limbs.size()) {
		this->limbs[i]->translation = Vector3f(0, 0, 0);
		this->limbs[i]->scale = Vector3f(1.0f, 1.0f, 1.0f);
		this->limbs[i]->rotation = Vector3f(0, 0, 0);

		i++;
	}

	this->position();
}

void ABody::resetSelectedLimb(void)
{
	this->limbs[this->selectedLimb]->translation = Vector3f(0, 0, 0);
	this->limbs[this->selectedLimb]->scale = Vector3f(1.0f, 1.0f, 1.0f);
	this->limbs[this->selectedLimb]->rotation = Vector3f(0, 0, 0);

	this->position();
}

ABody &ABody::operator=(ABody const &rhs)
{
	this->bodyIndex = rhs.bodyIndex;
	this->limbs = rhs.getLimbs();
	this->selectedLimb = rhs.getSelectedLimb();
	this->_textures = rhs.getTextures();
	return *this;
}


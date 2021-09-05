#ifndef HUMANBODY_HPP
#define HUMANBODY_HPP

#include "HumanGL.hpp"

class HumanBody : public ABody
{
private:
	void generateLimbs(void);

public:
	HumanBody(void);
	HumanBody(int bodyIndex_);
	HumanBody(HumanBody const &c);
	~HumanBody(void);

	void position(void);

	HumanBody &operator=(HumanBody const &rhs);
};


#endif

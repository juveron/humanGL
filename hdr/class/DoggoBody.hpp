#ifndef DOGGOBODY_HPP
#define DOGGOBODY_HPP

#include "HumanGL.hpp"

class DoggoBody : public ABody
{
private:
	void generateLimbs(void);

public:
	DoggoBody(void);
	DoggoBody(DoggoBody const &c);
	~DoggoBody(void);

	void position(void);

	DoggoBody &operator=(DoggoBody const &rhs);
};



#endif

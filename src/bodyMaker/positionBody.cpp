#include "HumanGL.hpp"

void positionBody(s_body &body, s_indexBody indexBody)
{
	if (indexBody.drawBody & 1)
		positionHumanLimbs(body.limbs);
	if ((indexBody.drawBody >> 1) & 1)
		positionDoggoLimbs(body.limbs);
}

//
// Created by juv on 27/07/2021.
//
#include "HumanGL.hpp"

void	initBody(s_body &body, int &currentIndex)
{

	size_t i = 0;
	while (i < body.limbs.size()) {
		body.limbs[i]->translation = Vector3f(0, 0, 0);
		body.limbs[i]->scale = Vector3f(1.0f, 1.0f, 1.0f);
		body.limbs[i]->rotation = Vector3f(0, 0, 0);

		i++;
	}
	if (currentIndex == 0) positionHumanLimbs(body.limbs); else positionDoggoLimbs(body.limbs);
};

void	initLimb(s_body &body, int &currentIndex)
{
	body.limbs[body.selectedLimb]->translation = Vector3f(0, 0, 0);
	body.limbs[body.selectedLimb]->scale = Vector3f(1.0f, 1.0f, 1.0f);
	body.limbs[body.selectedLimb]->rotation = Vector3f(0, 0, 0);

	if (currentIndex == 0) positionHumanLimbs(body.limbs); else positionDoggoLimbs(body.limbs);
}

//
// Created by juv on 27/07/2021.
//
#include "HumanGL.hpp"

void	initBody(s_body &body) {

	size_t i = 0;
	while (i < body.limbs.size()) {
		body.limbs[i]->translation = Vector3f(0, 0, 0);
//		body.limbs[i]->scale = Vector3f(0, 0, 0);
		body.limbs[i]->rotation = Vector3f(0, 0, 0);

		i++;
	}
	positionHumanLimbs(body.limbs);
};

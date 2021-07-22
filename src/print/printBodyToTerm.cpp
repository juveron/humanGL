#include "../../hdr/HumanGL.hpp"

void printBodyToTerm(s_body &body)
{
	int i = 0;
	std::vector<Limb *>::iterator iter = body.limbs.begin();
	std::vector<Limb *>::iterator iterEnd = body.limbs.end();

	while (iter != iterEnd)
	{
		std::cout << "=============\nIndex " << i << ":\n-> Current Mat:" << std::endl;
		(*iter)->currentMat.print();
		std::cout << "-> Scale Mat:" << std::endl;
		(*iter)->scaleMat.print();

		i++;
		iter++;
	}
}


#include "../../hdr/HumanGL.hpp"

void printBodyToTerm(Limb *limb)
{
	static int i = 0;
	int baseValue = i;
	std::vector<Limb *>::iterator iter = limb->children.begin();
	std::vector<Limb *>::iterator iterEnd = limb->children.end();

	std::cout << "=============\nIndex " << i << ":\n-> Current Mat:" << std::endl;
	limb->currentMat.print();
	std::cout << "-> Scale Mat:" << std::endl;
	limb->scaleMat.print();

	while (iter != iterEnd)
	{
		i++;
		printBodyToTerm(*iter);
		iter++;
	}
}


#include "../../hdr/HumanGL.hpp"

static void printBody(Limb *limb, std::ofstream &file)
{
	std::vector<Limb *>::iterator iter = limb->children.begin();
	std::vector<Limb *>::iterator iterEnd = limb->children.end();

	int i = 0;
	file << "\t{ Matrix4({ ";
	while (i < 16)
	{
		file << limb->currentMat.matrix[i];
		if (i != 15)
			file << ", ";
		i++;
	}
	i = 0;
	file << " }), Matrix4({ ";
	while (i < 16)
	{
		file << limb->scaleMat.matrix[i];
		if (i != 15)
			file << ", ";
		i++;
	}
	file << " }) }," << std::endl;

	while (iter != iterEnd)
	{
		printBody(*iter, file);
		iter++;
	}
}

void printBodyToFile(Limb *limb, std::string fileName)
{
	std::ofstream file;

	file.exceptions(std::ofstream::failbit | std::ofstream::badbit);

	try {
		file.open(fileName);
		file << "{" << std::endl;
		printBody(limb, file);
		file << "}" << std::endl;
		file.close();
	}
	catch (std::ofstream::failure &e)
	{
		std::cerr << "Unable to open/read/close:" << e.what() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

#include "HumanGL.hpp"

static void printBody(s_body &body, std::ofstream &file)
{
	std::vector<Limb *>::iterator iter = body.limbs.begin();
	std::vector<Limb *>::iterator iterEnd = body.limbs.end();

	while (iter != iterEnd)
	{
		file << "\t{ Vector3f(" << (*iter)->rotation.x << "," << (*iter)->rotation.y << "," << (*iter)->rotation.z << "),";
		file << " Vector3f(" << (*iter)->translation.x << "," << (*iter)->translation.y << "," << (*iter)->translation.z << "),";
		file << " Vector3f(" << (*iter)->scale.x << "," << (*iter)->scale.y << "," << (*iter)->scale.z << ") }," << std::endl;

		iter++;
	}
}

void printBodyToFile(s_body &body, std::string fileName)
{
	std::ofstream file;

	file.exceptions(std::ofstream::failbit | std::ofstream::badbit);

	try {
		file.open(fileName);
		file << "{" << std::endl;
		printBody(body, file);
		file << "}," << std::endl;
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

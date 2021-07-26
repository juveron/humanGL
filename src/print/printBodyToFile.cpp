#include "../../hdr/HumanGL.hpp"

static void printBody(s_body &body, std::ofstream &file)
{
	std::vector<Limb *>::iterator iter = body.limbs.begin();
	std::vector<Limb *>::iterator iterEnd = body.limbs.end();

	while (iter != iterEnd)
	{
		int i = 0;
		file << "\t{ Matrix4((float const[]) { ";
		while (i < 16)
		{
			file << (*iter)->currentMat.matrix[i];
			if (i != 15)
				file << ", ";
			i++;
		}
		i = 0;
		file << " }), Matrix4((float const[]) { ";
		while (i < 16)
		{
			file << (*iter)->scaleMat.matrix[i];
			if (i != 15)
				file << ", ";
			i++;
		}
		file << " }) }," << std::endl;

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

#include "Fetch.h"


void BRFImporter::Fetch::LoadFile(std::string fileName)
{
	char lenght = 0;
	std::ifstream file;
	file.open("source.pdf", std::ios::binary | std::ios::in);

	if (!file.is_open())
	{
		std::cout << "Failed opening file";
	}
	else
	{
		std::string meshInfo;
		file.read((char*)&meshInfo, lenght);
	}
	
	file.close();

	//read file
	// read meshdata
	//fill structs for meshdata with data
	// create instance of right subclass (like meshdata); call meshdata constructor; fill meshdatas structs weith data; (skicka in structarna)
	// remove the temp structs;

}

//CON
BRFImporter::Fetch::Fetch(std::string fileName)
{
	FILE *fopen(const char * filename, const char * mode); // opens file and controlling stream withfopen

	//do file stuff here
}

BRFImporter::Fetch::Fetch()
{

}
//DECON
BRFImporter::Fetch::~Fetch()
{

}


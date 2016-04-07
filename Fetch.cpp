#include "Fetch.h"


void BRFImporter::Fetch::LoadFile(std::string fileName)
{
	char* fileInfo;
	char lenght = 0;


	file.open("test.bin", std::ios::binary);

	if (!file.is_open())
	{
		std::cout << "Failed opening file";
	}
	else
	{
		MeshData(fileInfo, lenght);
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
	//do file stuff here
}

//DECON
BRFImporter::Fetch::~Fetch()
{

}

void BRFImporter::Fetch::MeshData(char * fileInfo, char length)
{
	file.read((char*)&meshStruct, sizeof(meshStruct));


}

void BRFImporter::Fetch::MaterialData()
{
}

void BRFImporter::Fetch::SkeletonData()
{
}

void BRFImporter::Fetch::GroupData()
{
}

void BRFImporter::Fetch::LightData()
{
}

void BRFImporter::Fetch::AttrData()
{
}

void BRFImporter::Fetch::CameraData()
{
}

void BRFImporter::Fetch::MorphAnimData()
{
}

void BRFImporter::Fetch::AnimationData()
{
}

#include "FileData.h"
using namespace BRFImporterLib;
//FUNCTION DEFINITIONS FOR FILEDATA

void FileData::LoadFile(std::string fileName, bool mesh, bool light)
{	
	std::ifstream inFile(fileName, std::ifstream::binary);
	if (!inFile.is_open())
	{
		return;
	}
	else
	{
		int goldenNumber[2];

		inFile.read((char*)&goldenNumber, sizeof(int) * 2);

		if (goldenNumber[0] == 7 && goldenNumber[1] == 6)
		{
			LoadMain(&inFile);

			if (mesh == true)
			{
				LoadMesh(&inFile);
			}
			if (light == true)
			{
				LoadLight(&inFile);
			}
			
		}
	}
	//right?
	inFile.close();
	
}
//adds the mainheader info to the sent in fetch.
void FileData::LoadMain(std::ifstream *inFile)
{
	inFile->read((char*)&mainStruct, sizeof(MainHeader));
	this->fetch.setMain(&mainStruct);
}

//adds the meshheader and subsequents to the sent in fetch.
void FileData::LoadMesh(std::ifstream *inFile)
{
	

	meshStruct = new MeshHeader[this->fetch.getMain()->meshAmount];
	inFile->read((char*)meshStruct, sizeof(MeshHeader) * this->fetch.getMain()->meshAmount);

	thisMesh.setMeshData(meshStruct);

	vertices = new VertexHeader[meshStruct->vertexCount];
	inFile->read((char*)vertices, sizeof(VertexHeader) * meshStruct->vertexCount);

	thisMesh.setVertexData(vertices);

	indices = new IndexHeader[meshStruct->indexCount];
	inFile->read((char*)indices, sizeof(IndexHeader) * meshStruct->indexCount);

	thisMesh.setIndexData(indices);

	this->fetch.setMeshes(&thisMesh);
}

void FileData::LoadLight(std::ifstream *inFile)
{

}


FileData::FileData()
{

}

FileData::~FileData()
{
	delete meshStruct;
	delete vertices;
	delete indices;
	thisMesh.~MeshData();
	fetch.~Fetch();
}


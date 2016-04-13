#include "FileData.h"
using namespace BRFImporterLib;
//FUNCTION DEFINITIONS FOR FILEDATA

void FileData::LoadFile(Fetch Fetch, std::string fileName, bool mesh, bool light)
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
			LoadMain(Fetch, &inFile);

			if (mesh == true)
			{
				LoadMesh(Fetch, &inFile);
			}
			if (light == true)
			{
				LoadLight(Fetch, &inFile);
			}
			
		}
	}
	//right?
	inFile.close();
	
}
//adds the mainheader info to the sent in fetch.
void FileData::LoadMain(Fetch Fetch, std::ifstream *inFile)
{
	MainHeader mainStruct;
	inFile->read((char*)&mainStruct, sizeof(MainHeader));
	Fetch.setMain(&mainStruct);
}

//adds the meshheader and subsequents to the sent in fetch.
void FileData::LoadMesh(Fetch Fetch, std::ifstream *inFile)
{
	//UNFINISHED
	MeshData thisMesh;

	MeshHeader meshStruct;
	inFile->read((char*)&meshStruct, sizeof(MeshHeader));

	thisMesh.setMeshData(meshStruct);

	VertexHeader* vertices = new VertexHeader[meshStruct.vertexCount];
	inFile->read((char*)vertices, sizeof(VertexHeader) * meshStruct.vertexCount);

	thisMesh.setVertexData(vertices);

	IndexHeader* indices = new IndexHeader[meshStruct.indexCount];
	inFile->read((char*)indices, sizeof(IndexHeader) * meshStruct.indexCount);

	thisMesh.setIndexData(indices);

	Fetch.setMeshes(&thisMesh);
}

void FileData::LoadLight(Fetch Fetch, std::ifstream *inFile)
{

}


FileData::FileData()
{

}

FileData::~FileData()
{

}


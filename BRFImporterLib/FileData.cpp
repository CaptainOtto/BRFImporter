#include "FileData.h"
using namespace BRFImporterLib;
//FUNCTION DEFINITIONS FOR MESHDATA

//ALL FILE LOADING AND DISTRIBUTING OF DATA TO ALL FOUND SECTIONS
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
	
}

void FileData::LoadMesh(std::ifstream *inFile)
{
	//UNFINISHED
	MeshData thisMesh;
	thisMesh.setMeshData;

	MeshHeader meshStruct;
	inFile->read((char*)&meshStruct, sizeof(MeshHeader));

	VertexHeader* vertices = new VertexHeader[meshStruct.vertexCount];
	inFile->read((char*)vertices, sizeof(VertexHeader) * meshStruct.vertexCount);

	thisMesh.setVertexData(vertices);

	IndexHeader* indices = new IndexHeader[meshStruct.indexCount];
	inFile->read((char*)indices, sizeof(IndexHeader) * meshStruct.indexCount);

	thisMesh.setIndexData(indices);


}

void FileData::LoadLight(std::ifstream *inFile)
{

}


FileData::FileData()
{

}

FileData::~FileData()
{

}


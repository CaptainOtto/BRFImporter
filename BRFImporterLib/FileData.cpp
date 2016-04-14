#include "FileData.h"
#include <crtdbg.h>
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
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
	inFile.close();
	fetch = new Fetch(mainStruct, thisMeshArray);
	//fetch = new Fetch(mainStruct, thisMesh, thisLight);

	//delete[] thisMeshArray;
	//delete mainStruct;
}
//adds the mainheader info to the sent in fetch.
void FileData::LoadMain(std::ifstream *inFile)
{
	mainStruct = new MainHeader;
	inFile->read((char*)mainStruct, sizeof(MainHeader));
}

//adds the meshheader and subsequents to the sent in fetch.
void FileData::LoadMesh(std::ifstream *inFile)
{

	thisMeshArray = new MeshData[mainStruct->meshAmount];

	for (unsigned int i = 0; i < (mainStruct->meshAmount); i++)
	{
		//MESHHEADER
		meshStruct = new MeshHeader;
		inFile->read((char*)meshStruct, sizeof(MeshHeader));

		thisMeshArray[i].SetMeshData(meshStruct);

		//BBOX
		if (meshStruct->boundingBox == true)
		{
			//do the BBOX READ
		}

		//VERTICES SKEL/NOSKEL
		if (meshStruct->hasSkeleton == true)
		{
			vertices = new VertexHeader[meshStruct->vertexCount];
			inFile->read((char*)vertices, sizeof(VertexHeader) * meshStruct->vertexCount);
			
			thisMeshArray[i].SetVertexData(vertices);
			delete[] vertices;
		}
		else 
		{
			verticesNoSkeleton = new VertexHeaderNoSkeleton[meshStruct->vertexCount];
			inFile->read((char*)verticesNoSkeleton, sizeof(VertexHeaderNoSkeleton) * meshStruct->vertexCount);
			
			thisMeshArray[i].SetVertexNoSkeletonData(verticesNoSkeleton);
			delete[] verticesNoSkeleton;
		}

		//INDICES
		indices = new IndexHeader[meshStruct->indexCount];
		inFile->read((char*)indices, sizeof(IndexHeader) * meshStruct->indexCount);

		thisMeshArray[i].SetIndexData(indices);
		delete[] indices;
		delete meshStruct;
	}

}

void FileData::LoadLight(std::ifstream *inFile)
{

}



//CON DECON
FileData::FileData()
{

}
FileData::~FileData()
{
	delete fetch;
	delete mainStruct;
	
}


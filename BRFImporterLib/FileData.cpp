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
	inFile.close();
}
//adds the mainheader info to the sent in fetch.
void FileData::LoadMain(std::ifstream *inFile)
{
	inFile->read((char*)&mainStruct, sizeof(MainHeader));
	
}

//adds the meshheader and subsequents to the sent in fetch.
void FileData::LoadMesh(std::ifstream *inFile)
{

	thisMesh = new MeshData[mainStruct.meshAmount];

	for (unsigned int i = 0; i <= (mainStruct.meshAmount - 1); i++)
	{
		//MESHHEADER
		inFile->read((char*)meshStruct, sizeof(MeshHeader));

		thisMesh[i].SetMeshData(meshStruct);

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
			
			thisMesh[i].SetVertexData(vertices);
		}
		else 
		{
			verticesNoSkeleton = new VertexHeaderNoSkeleton[meshStruct->vertexCount];
			inFile->read((char*)verticesNoSkeleton, sizeof(VertexHeaderNoSkeleton) * meshStruct->vertexCount);
			
			thisMesh[i].SetVertexNoSkeletonData(verticesNoSkeleton);
		}

		//INDICES
		indices = new IndexHeader[meshStruct->indexCount];
		inFile->read((char*)indices, sizeof(IndexHeader) * meshStruct->indexCount);

		thisMesh[i].SetIndexData(indices);
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
	delete meshStruct;
	delete vertices;
	delete indices;
	thisMesh->~MeshData();
	fetch.~Fetch();
}


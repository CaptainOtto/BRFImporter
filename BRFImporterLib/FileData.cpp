#include "FileData.h"
#include <crtdbg.h>
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
using namespace BRFImporterLib;
//FUNCTION DEFINITIONS FOR FILEDATA

void FileData::LoadFile(std::string fileName, bool mesh)
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
		}
	}
	inFile.close();
	this->fetch = new Fetch(tempMain, meshArray);
}

//adds the mainheader info to the sent in fetch.
void FileData::LoadMain(std::ifstream *inFile)
{
	tempMain = new MainHeader;
	inFile->read((char*)tempMain, sizeof(MainHeader));
}
//adds the meshheader and subsequents to the sent in fetch.
void FileData::LoadMesh(std::ifstream *inFile)
{
	//array with all meshes
	std::unique_ptr<MeshData[]> meshArray(new MeshData[tempMain->meshAmount]);

	for (unsigned int i = 0; i < (tempMain->meshAmount); i++)
	{

		std::shared_ptr<MeshHeader> tempMesh(new MeshHeader);
		inFile->read((char*)tempMesh.get(), sizeof(MeshHeader));

		meshArray[i].SetData(tempMesh);

		//VERTICES SKEL/NOSKEL
		if (tempMesh->hasSkeleton == true)
		{
			std::unique_ptr<VertexHeader> tempVertices(new VertexHeader[tempMesh->vertexCount]);
			inFile->read((char*)tempVertices.get(), sizeof(VertexHeader) * tempMesh->vertexCount);

			meshArray.get()[i].SetVertexData(tempVertices.get());
			tempVertices.reset();
		}
		else 
		{
			std::unique_ptr<VertexHeaderNoSkeleton> tempVerticesNoSkel(new VertexHeaderNoSkeleton[tempMesh->vertexCount]);
			inFile->read((char*)tempVerticesNoSkel.get(), sizeof(VertexHeaderNoSkeleton) * tempMesh->vertexCount);
			
			meshArray.get()[i].SetVertexNoSkeletonData(tempVerticesNoSkel.get());
			tempVerticesNoSkel.reset();
		}

		//INDICES
		std::unique_ptr<IndexHeader> tempIndices(new IndexHeader[tempMesh->indexCount]);
		inFile->read((char*)tempIndices.get() , sizeof(IndexHeader) * tempMesh->indexCount);

		meshArray.get()[i].SetIndexData(tempIndices.get());
		
		tempIndices.reset();
		tempMesh.reset();
	}

}

//CON DECON
FileData::FileData()
{

}
FileData::~FileData()
{
	

	delete[] meshArray;
	delete tempMain;
	delete fetch;

}


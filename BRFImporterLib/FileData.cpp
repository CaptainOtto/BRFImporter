#include "FileData.h"
#include <crtdbg.h>
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
using namespace BRFImporterLib;
//FUNCTION DEFINITIONS FOR FILEDATA

void FileData::LoadFile(std::string fileName, bool mesh)
{
	std::shared_ptr<FetchContainer> tempFetchData(new FetchContainer);
	this->SrcFetchData = tempFetchData;
	tempFetchData.reset();

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
			std::shared_ptr<MainHeader> tempMain(new MainHeader);  //GET ME INSIDE FETCH
			
			//constant loads
			LoadMain(tempMain, &inFile);

			//dynamic loads here, expand bools as neccesary
			if (mesh == true)
			{
				LoadMesh(tempMain, &inFile);
			}




			tempMain.reset();
		}
	}

	inFile.close();


	
	std::shared_ptr<Fetch> tempFetch(new Fetch(this->SrcFetchData));
	this->fetch = tempFetch;
	tempFetch.reset();
	this->SrcFetchData.reset();
	

}
//adds the mainheader info to the sent in fetch.
void FileData::LoadMain(std::shared_ptr<MainHeader> tempMain, std::ifstream *inFile)
{
	inFile->read((char*)tempMain.get(), sizeof(MainHeader));
	this->SrcFetchData->mainData = tempMain;
}
//adds the meshheader and subsequents to the sent in fetch.
void FileData::LoadMesh(std::shared_ptr<MainHeader> tempMain, std::ifstream *inFile)
{
	//array with all meshes
	std::unique_ptr<MeshData[]> meshArray(new MeshData[tempMain->meshAmount]); //GET ME INSIDE FETCH

	for (unsigned int i = 0; i < (tempMain->meshAmount); i++)
	{
		//crate SrcMeshData struct
		std::shared_ptr<MeshContainer> SrcMeshData(new MeshContainer);

		//read meshheader
		inFile->read((char*)SrcMeshData->meshData.get(), sizeof(MeshHeader));

		//read vertices
		if (SrcMeshData->meshData.get()->hasSkeleton == true)
		{
			inFile->read((char*)SrcMeshData->vertexData.get() , sizeof(VertexHeader) * SrcMeshData->meshData.get()->vertexCount);
		}
		else 
		{
			inFile->read((char*)SrcMeshData->vertexNoSkeletonData.get(), sizeof(VertexHeaderNoSkeleton) * SrcMeshData->meshData.get()->vertexCount);
		}

		//read indices
		inFile->read((char*)SrcMeshData->indexData.get() , sizeof(IndexHeader) * SrcMeshData->meshData.get()->indexCount);

		meshArray[i].SetData(SrcMeshData);
		SrcMeshData.reset();
	}
}

//CON DECON
FileData::FileData()
{

}
FileData::~FileData()
{
	
}


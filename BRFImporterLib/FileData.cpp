#include "FileData.h"
#include <crtdbg.h>
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
using namespace BRFImporterLib;
//FUNCTION DEFINITIONS FOR FILEDATA

void FileData::LoadFile(std::string fileName, bool mesh, bool skeleton, bool material)
{
	std::shared_ptr<MainHeader> tempMain(new MainHeader);
	std::vector<std::shared_ptr<MeshData>> meshVector;
	std::shared_ptr<MaterialData> tempMaterialData(new MaterialData);

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
			//adds the mainheader info to the sent in fetch.
			std::shared_ptr<MainHeader> temp(new MainHeader);
			inFile.read((char*)temp.get(), sizeof(MainHeader));
			tempMain = temp;
			temp.reset();

			//dynamic loads here, expand bools as neccesary
			if (mesh == true)
			{
				meshVector = LoadMesh(tempMain, &inFile);
			}
			if (skeleton == true)
			{
				//meshVector = LoadSkeleton(tempMain, &inFile);
			}
			if (material == true)
			{
				tempMaterialData = LoadMaterial(tempMain, &inFile);
			}
		}
	}

	inFile.close();
	
	
	std::shared_ptr<FetchContainer> tempFetchData(new FetchContainer(tempMain, meshVector, tempMaterialData));
	std::shared_ptr<Fetch> tempFetch(new Fetch(tempFetchData));
	tempFetchData.reset();
	this->fetch = tempFetch;
	tempFetch.reset();
	tempFetchData.reset();
	

}


//adds the meshheader and subsequents to the sent in fetch.
std::vector<std::shared_ptr<MeshData>> FileData::LoadMesh(std::shared_ptr<MainHeader> tempMain, std::ifstream *inFile)
{
	std::vector<std::shared_ptr<MeshData>> meshVector;

	for (unsigned int i = 0; i < (tempMain->meshAmount); i++)
	{
		//push me to the meshvector and reset me!
		std::shared_ptr<MeshData> tempMesh(new MeshData);

		//read meshheader
		std::shared_ptr<MeshHeader> tempMeshHeader(new MeshHeader);
		inFile->read((char*)tempMeshHeader.get(), sizeof(MeshHeader));

		//crate SrcMeshData struct
		std::shared_ptr<MeshContainer> SrcMeshData(new MeshContainer(tempMeshHeader->vertexCount, tempMeshHeader->indexCount));

		SrcMeshData->meshData = tempMeshHeader;

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


		tempMesh->SetData(SrcMeshData);
		//SrcMeshData.reset();
		meshVector.push_back(tempMesh);
		tempMesh.reset();
	}
	return meshVector;
}

//adds the materialheader and subsequents to the sent in fetch
std::shared_ptr<MaterialData> BRFImporterLib::FileData::LoadMaterial(std::shared_ptr<MainHeader> tempMain, std::ifstream * inFile)
{
	std::shared_ptr<MaterialData> tempMaterialData(new MaterialData);

	for (unsigned int i = 0; i < tempMain->materialAmount; i++)
	{
		std::shared_ptr<MaterialContainer> tempMaterialContainer(new MaterialContainer);

		std::shared_ptr<MaterialHeader> tempMaterialHeader(new MaterialHeader);
		inFile->read((char*)tempMaterialHeader.get(), sizeof(MaterialHeader));

		unsigned int tempID = tempMaterialHeader.get()->Id;


		std::string tempName;
		tempName = std::string(tempMaterialHeader.get()->matName);
		tempMaterialContainer.get()->matName = tempName;

		std::string tempDiff;
		tempDiff = std::string(tempMaterialHeader.get()->diffMap);
		tempMaterialContainer.get()->diffMap = tempDiff;

		std::string tempSpec;
		tempSpec = std::string(tempMaterialHeader.get()->specMap);
		tempMaterialContainer.get()->specMap = tempSpec;

		std::string tempNorm;
		tempNorm = std::string(tempMaterialHeader.get()->normalMap);
		tempMaterialContainer.get()->normalMap = tempNorm;

		std::string tempRef;
		tempRef = std::string(tempMaterialHeader.get()->reflectMap);
		tempMaterialContainer.get()->reflectMap = tempRef;

		std::string tempGlow;
		tempGlow = std::string(tempMaterialHeader.get()->glowMap);
		tempMaterialContainer.get()->glowMap = tempGlow;

		tempMaterialContainer.get()->Id = tempMaterialHeader.get()->Id;

		for (int j = 0; j < 3; j++)
		{
			tempMaterialContainer->ambientVal[j] = tempMaterialHeader->ambientVal[j];
		}
		for (int j = 0; j < 3; j++)
		{
			tempMaterialContainer->diffuseVal[j] = tempMaterialHeader->diffuseVal[j];
		}
		for (int j = 0; j < 3; j++)
		{
			tempMaterialContainer->specularVal[j] = tempMaterialHeader->specularVal[j];
		}

		tempMaterialData->SetData(tempMaterialContainer);
	}

	return tempMaterialData;
}

//start

//skeletonheader (baserat på hur mnga sklätt körs rästen per sklätt)
	//jointheader (baseras på joint amt)

	//animationheader (baserat på ani mat)
		// ^ säger hur många jointcountheaders ska läsas, som säger hur mnga frames
			// en frameheader inläsning loop
	//spottar kombinerade resultatet in i skeletoncontainer

//returna sen alla skletts animationer
//end



//CON DECON
FileData::FileData()
{

}
FileData::~FileData()
{
	
}


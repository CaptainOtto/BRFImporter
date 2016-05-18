#include "FileData.h"
#include <crtdbg.h>
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
using namespace BRFImporterLib;
//FUNCTION DEFINITIONS FOR FILEDATA

//oh chucklesticks! this loads a file!
void FileData::LoadFile(std::string fileName, bool mesh, bool skeleton, bool material, bool morph)
{
	std::shared_ptr<MainHeader> tempMain(new MainHeader);
	std::vector<std::shared_ptr<MeshData>> meshVector;
	std::shared_ptr<MaterialData> tempMaterialData(new MaterialData);
	std::vector<std::shared_ptr<SkeletonData>> skeletonVector;
	std::vector<std::shared_ptr<MorphData>> morphVector;

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
			if (material == true)
			{
				tempMaterialData = LoadMaterial(tempMain, &inFile);
			}
			if (skeleton == true)
			{
				skeletonVector = LoadSkeleton(tempMain, &inFile);
			}
			if (morph == true)
			{
				//ta emot morphDatan!!!!
				morphVector = LoadMorph(tempMain, &inFile);
			}
		}
	}

	inFile.close();
	
	
	std::shared_ptr<FetchContainer> tempFetchData(new FetchContainer(tempMain, meshVector, tempMaterialData, skeletonVector, morphVector));
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
			inFile->read((char*)SrcMeshData->weightData.get(), sizeof(WeigthsHeader) * SrcMeshData->meshData.get()->vertexCount * 4);
		}
		else 
		{
			inFile->read((char*)SrcMeshData->vertexData.get(), sizeof(VertexHeaderNoSkeleton) * SrcMeshData->meshData.get()->vertexCount);
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

std::vector<std::shared_ptr<SkeletonData>> BRFImporterLib::FileData::LoadSkeleton(std::shared_ptr<MainHeader> tempMain, std::ifstream * inFile)
{
	std::vector<std::shared_ptr<SkeletonData>> tempSkeletonVector;


	for (unsigned int i = 0; i < tempMain->skeletonAmount; i++)
	{
		std::shared_ptr<SkeletonData> tempSkeletonData(new SkeletonData);

		//skeletondata
		std::shared_ptr<SkeletonHeader> tempSkeletonHeader(new SkeletonHeader);
		inFile->read((char*)tempSkeletonHeader.get(), sizeof(SkeletonHeader));

		//skapar tempcontainer
		std::shared_ptr<SkeletonContainer> tempSkeletonContainer(new SkeletonContainer(tempSkeletonHeader->jointCount, tempSkeletonHeader->animationCount));

		tempSkeletonContainer->skeletonData = tempSkeletonHeader;
		tempSkeletonHeader.reset();

		//jointdata
		inFile->read((char*)tempSkeletonContainer->jointData.get(), sizeof(JointHeader) * tempSkeletonContainer->skeletonData->jointCount);

		//animationData
		inFile->read((char*)tempSkeletonContainer->animationData.get(), sizeof(AnimationHeader) * tempSkeletonContainer->skeletonData->animationCount);

		SkeletonContainer* doubleSkeletonContainer = tempSkeletonContainer->GetSkeletonContainer();
		doubleSkeletonContainer->SetFrameDataContainer(tempSkeletonContainer->animationData.get()->jointCount);

		for (unsigned int j = 0; j < tempSkeletonContainer->skeletonData->animationCount; j++)
		{
			for (unsigned int k = 0; k < tempSkeletonContainer->animationData.get()->jointCount; k++)
			{
				inFile->read((char*)tempSkeletonContainer->frameDataContainer[k].get()->animationJointData.get(), sizeof(JointCountHeader));

				for (unsigned int l = 0; l < tempSkeletonContainer->frameDataContainer[k].get()->animationJointData.get()->frameCount; l++)
				{
					std::shared_ptr<FrameHeader> tempFrameArray(new FrameHeader);
					inFile->read((char*)tempFrameArray.get(), sizeof(FrameHeader));

					//tempSkeletonContainer->frameDataContainer.get()->frameData.push_back(tempFrameArray);
					tempSkeletonContainer->frameDataContainer[k].get()->frameData.push_back(tempFrameArray);
				}
			}

		}
		tempSkeletonData->setData(tempSkeletonContainer);

		tempSkeletonVector.push_back(tempSkeletonData);
	}

	return tempSkeletonVector;
}

std::vector<std::shared_ptr<MorphData>> BRFImporterLib::FileData::LoadMorph(std::shared_ptr<MainHeader> tempMain, std::ifstream * inFile)
{
	std::vector<std::shared_ptr<MorphData>> DestMorphData;

	for (size_t i = 0; i < tempMain->morphAnimAmount; i++)
	{
		std::shared_ptr<MorphData> tempMorphData(new MorphData);

		std::shared_ptr<MorphAnimHeader> tempAnimHeader(new MorphAnimHeader);
		inFile->read((char*)tempAnimHeader.get(), sizeof(MorphAnimHeader));

		std::shared_ptr<MorphDataContainer> SrcMorphData(new MorphDataContainer(tempAnimHeader->numberOfKeyFrames, tempAnimHeader->vertsPerShape));

		SrcMorphData->morphData = tempAnimHeader;

		for (size_t i = 0; i < SrcMorphData->morphData->numberOfKeyFrames; i++)
		{
			inFile->read((char*)&SrcMorphData->morphKeyFrameData[i], sizeof(MorphAnimKeyFrameHeader));
			for (size_t j = 0; j < SrcMorphData->morphData->vertsPerShape; j++)
			{
				MorphVertexHeader temp;
				inFile->read((char*)&temp, sizeof(MorphVertexHeader));
				SrcMorphData->morphVertexData[i].push_back(temp);
			}
		}
		tempMorphData->setData(SrcMorphData);
		DestMorphData.push_back(tempMorphData);
	}


	return DestMorphData;
}

//CON DECON
FileData::FileData()
{

}
FileData::~FileData()
{
	
}


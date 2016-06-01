#include "FileData.h"
#include <crtdbg.h>
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
using namespace BRFImporterLib;
//FUNCTION DEFINITIONS FOR FILEDATA

//oh chucklesticks! this loads a file!
void FileData::LoadFile(std::string fileName, bool mesh, bool skeleton, bool material, bool light, bool morph,bool groups)
{
	std::shared_ptr<MainHeader> tempMain(new MainHeader);
	std::vector<std::shared_ptr<MeshData>> meshVector;
	std::shared_ptr<MaterialData> tempMaterialData(new MaterialData);
	std::vector<std::shared_ptr<SkeletonData>> skeletonVector;
	std::shared_ptr<LightData> tempLightData(new LightData);
	std::vector<std::shared_ptr<MorphData>> morphVector;
	std::vector<std::shared_ptr<GroupData>> groupVector;

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
			if (light == true)
			{
				tempLightData = LoadLight(tempMain, &inFile);
			}
			if (morph == true)
			{
				//ta emot morphDatan!!!!
				morphVector = LoadMorph(tempMain, &inFile);
			}
			if (groups == true)
			{
				groupVector = LoadGroups(tempMain, &inFile);
			}
		}
	}

	inFile.close();
	
	
	std::shared_ptr<FetchContainer> tempFetchData(new FetchContainer(tempMain, meshVector, tempMaterialData, skeletonVector,tempLightData,  morphVector,groupVector));
	std::shared_ptr<Fetch> tempFetch(new Fetch(tempFetchData));
	tempFetchData.reset();
	this->fetch = tempFetch;
	tempFetch.reset();
	tempFetchData.reset();

	

}


//Adds the meshheader and subsequents to be sent to fetch.
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

//Adds the materialheader and subsequents to be sent to fetch.
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

//Adds the skeletonHeader and subsequents to be sent to fetch.
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

//Adds the lightHeader and subsequents to be sent to fetch.
std::shared_ptr<LightData> BRFImporterLib::FileData::LoadLight(std::shared_ptr<MainHeader> tempMain, std::ifstream * inFile)
{
	if (tempMain->lights == false)
	{
		return nullptr;
	}
	else if (tempMain->lights == true)
	{
		std::shared_ptr<LightData> SrcLightData;

		std::shared_ptr<LightHeader> tempLightHeader;
		inFile->read((char*)tempLightHeader.get(), sizeof(LightHeader));

		std::shared_ptr<LightContainer> tempLightContainer(new LightContainer(tempLightHeader->spotCount, tempLightHeader->areaCount, tempLightHeader->pointCount, tempLightHeader->directionalCount));
		tempLightContainer->lightData = tempLightHeader;
		tempLightHeader.reset();

		if (tempLightContainer->lightData->spotCount != 0)
		{
			inFile->read((char*)tempLightContainer->spotLightData.get(), sizeof(SpotLightHeader) * tempLightContainer->lightData->spotCount);
		}
		if (tempLightContainer->lightData->areaCount != 0)
		{
			inFile->read((char*)tempLightContainer->areaLightData.get(), sizeof(AreaLightHeader) * tempLightContainer->lightData->areaCount);
		}
		if (tempLightContainer->lightData->pointCount != 0)
		{
			inFile->read((char*)tempLightContainer->pointLightData.get(), sizeof(PointLightHeader) * tempLightContainer->lightData->pointCount);
		}
		if (tempLightContainer->lightData->directionalCount != 0)
		{
			inFile->read((char*)tempLightContainer->dirLightData.get(), sizeof(DirLightHeader) * tempLightContainer->lightData->directionalCount);
		}

		SrcLightData->SetData(tempLightContainer);
		tempLightContainer.reset();
		return SrcLightData;
	}
	else
	{
		return nullptr;
	}
}

//Adds the morphdata and subsequents to be sent to fetch.
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

std::vector<std::shared_ptr<GroupData>> BRFImporterLib::FileData::LoadGroups(std::shared_ptr<MainHeader> tempMain, std::ifstream * inFile)
{

	std::vector<std::shared_ptr<GroupData>> tmpGroupVector;
	tmpGroupVector.reserve(tempMain->groupAmount);

	for (unsigned int i = 0; i < tempMain->groupAmount; i++) //for every group
	{

		std::shared_ptr<GroupData> tempGroup;	 
		std::shared_ptr<GroupHeader> tempGrpHeader;

		inFile->read((char*)tempGrpHeader.get(), sizeof(GroupHeader)); // Read the group header data

		std::shared_ptr<GroupContainer> grpContainer(new GroupContainer(tempGrpHeader->attrCount));

		grpContainer->groupData = tempGrpHeader;
		tempGrpHeader.reset();

		inFile->read((char*)grpContainer->attributeType.get(), sizeof(GroupAttributeHeader) * grpContainer->groupData->attrCount);

		tempGroup->SetData(grpContainer);
		tmpGroupVector.push_back(tempGroup);
		tempGroup.reset();
	}


	for (unsigned int i = 0; i < tempMain->groupAmount; i++)
	{																										    
																											    
		unsigned int n_vecAttributes	= 0;																    
		unsigned int n_stringAttributes = 0;																    
		unsigned int n_floatAttributes  = 0;																    
		unsigned int n_boolAttributes   = 0;																    
		unsigned int n_intAttributes    = 0;																    

		for (unsigned int attr = 0; attr < tmpGroupVector.at(i)->getGroupData()->groupData->attrCount; attr++) //for every attribute on the group
		{
			
			
			unsigned int attrType = tmpGroupVector.at(i)->getGroupData()->attributeType[attr].attrNr;
			switch (attrType)
			{
				case 0:			// Bool
				{n_boolAttributes += 1;													  
					break;																  
				}																//This loop is because we don't know how much we have of everything. (a miss in the exporter)		  
				case 1:			// float										//This loop is because we don't know how much we have of everything. (a miss in the exporter)
				{n_floatAttributes += 1;										//This loop is because we don't know how much we have of everything. (a miss in the exporter)
					break;														//This loop is because we don't know how much we have of everything. (a miss in the exporter)		  
				}																//This loop is because we don't know how much we have of everything. (a miss in the exporter)
				case 2:			// int											//This loop is because we don't know how much we have of everything. (a miss in the exporter)
				{n_intAttributes += 1;											//This loop is because we don't know how much we have of everything. (a miss in the exporter)
					break;																  
				}
				case 3:			// String
				{n_stringAttributes += 1;
					break;
				}
				case 4:			// vector
				{n_vecAttributes +=1 ;
					break;		
				}
			}
		}
		if (n_boolAttributes > 0)		// Read in the Bool attributes
		{
			tmpGroupVector.at(i)->getGroupData()->boolAttributes = std::unique_ptr <BoolAttrHeader[]>(new BoolAttrHeader[n_boolAttributes]);
			inFile->read((char*)tmpGroupVector.at(i)->getGroupData()->boolAttributes.get(), sizeof(BoolAttrHeader)* n_boolAttributes);
		}
		if( n_floatAttributes > 0)		//Read in the Float attributes
		{
			tmpGroupVector.at(i)->getGroupData()->floatAttributes = std::unique_ptr <FloatAttrHeader[]>(new FloatAttrHeader[n_floatAttributes]);
			inFile->read((char*)tmpGroupVector.at(i)->getGroupData()->floatAttributes.get(), sizeof(FloatAttrHeader) * n_floatAttributes);
		}
		if (n_intAttributes > 0)		//Read in the Int attributes
		{

			tmpGroupVector.at(i)->getGroupData()->intAttributes = std::unique_ptr <IntAttrHeader[]>(new IntAttrHeader[n_intAttributes]);
			inFile->read((char*)tmpGroupVector.at(i)->getGroupData()->intAttributes.get(), sizeof(IntAttrHeader)* n_intAttributes);
		}
		if (n_stringAttributes > 0)		// Read in the String attributes
		{

			tmpGroupVector.at(i)->getGroupData()->stringAttributes = std::unique_ptr <StringAttrHeader[]>(new StringAttrHeader[n_stringAttributes]);
			inFile->read((char*)tmpGroupVector.at(i)->getGroupData()->stringAttributes.get(), sizeof(StringAttrHeader)* n_stringAttributes);
		}
		if (n_vecAttributes > 0)	// Read in the vector attributes
		{
			tmpGroupVector.at(i)->getGroupData()->vecAttributes = std::unique_ptr <VectorAttrHeader[]>(new VectorAttrHeader[n_vecAttributes]);
			inFile->read((char*)tmpGroupVector.at(i)->getGroupData()->vecAttributes.get(), sizeof(VectorAttrHeader)* n_vecAttributes);
		}

	}


	return tmpGroupVector;
}


//CON DECON
FileData::FileData()
{

}
FileData::~FileData()
{
	
}


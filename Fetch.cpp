#include "Fetch.h"
#include <fstream>
#include <iostream>


void BRFImporter::Fetch::LoadFile(std::string fileName)
{
	//read file
	// read meshdata
	//fill structs for meshdata with data
	// create isntance of right subclass (like meshdata); call meshdata constructor; fill meshdatas structs weith data; (skicka in structarna)
	// remove the temp structs;
	
	

}






void BRFImporter::Fetch::LoadFile(std::string fileName)
{
	char* fileInfo;
	char lenght = 0;


	file.open("test.bin", std::ios::binary);

	if (!file.is_open())
	{
		std::cout << "Failed opening file";
	}
	else
	{
		MeshData();
		LightData();
		SkeletonData();
	}

	
	file.close();

	//read file
	// read meshdata
	//fill structs for meshdata with data
	// create instance of right subclass (like meshdata); call meshdata constructor; fill meshdatas structs weith data; (skicka in structarna)
	// remove the temp structs;

}

//CON

BRFImporter::Fetch::Fetch()
{

}

//DECON
BRFImporter::Fetch::~Fetch()
{

}

#pragma region Datapassthrough
void BRFImporter::Fetch::MeshData()
{

	BRFImporter::MeshHeader meshStruct; // Meshheader struct

	//reads file according to the vertexcount.
	file.read((char*)&meshStruct.vertexCount, sizeof(meshStruct.vertexCount));
	file.read((char*)&meshStruct.indexCount, sizeof(meshStruct.indexCount));
	file.read((char*)&meshStruct.boundingBox, sizeof(meshStruct.boundingBox));


	//Calls the default constructor of vertexheader
	BRFImporter::VertexHeader *vertices = new BRFImporter::VertexHeader[meshStruct.vertexCount];
	BRFImporter::IndexHeader *indices = new BRFImporter::IndexHeader[meshStruct.indexCount];
	BRFImporter::OOBBHeader *boundingBox = new BRFImporter::OOBBHeader[meshStruct.boundingBox];

	//Read all vertices in one go
	file.read((char*)vertices, meshStruct.vertexCount *sizeof(VertexHeader));
	file.read((char*)indices, meshStruct.indexCount*sizeof(IndexHeader));
	file.read((char*)boundingBox, meshStruct.boundingBox*sizeof(OOBBHeader));

	BRFImporter::MeshData::MeshData(*boundingBox, *indices, *vertices);

	delete boundingBox;
	delete indices;
	delete vertices;
}

void BRFImporter::Fetch::SkeletonData()
{
	BRFImporter::SkeletonHeader skeletonStruct;

	file.read((char*)&skeletonStruct.jointCount, sizeof(skeletonStruct.jointCount));
	file.read((char*)&skeletonStruct.animationCount, sizeof(skeletonStruct.animationCount));

	BRFImporter::SkeletonHeader *joints = new BRFImporter::SkeletonHeader[skeletonStruct.jointCount];
	BRFImporter::SkeletonHeader *animations = new BRFImporter::SkeletonHeader[skeletonStruct.animationCount];


	file.read((char*)joints, skeletonStruct.jointCount * sizeof(SkeletonHeader));
	file.read((char*)animations, skeletonStruct.animationCount * sizeof(SkeletonHeader));

	delete joints;
	delete animations;

}

void BRFImporter::Fetch::LightData()
{
	BRFImporter::LightHeader lightStruct;

	file.read((char*)&lightStruct.spotCount, sizeof(lightStruct.spotCount));
	file.read((char*)&lightStruct.directionalCount, sizeof(lightStruct.directionalCount));
	file.read((char*)&lightStruct.areaCount, sizeof(lightStruct.areaCount));
	file.read((char*)&lightStruct.pointCount, sizeof(lightStruct.pointCount));

	BRFImporter::SpotLightHeader *spotLight = new BRFImporter::SpotLightHeader[lightStruct.spotCount];
	BRFImporter::DirLightHeader *directionalLight = new BRFImporter::DirLightHeader[lightStruct.directionalCount];
	BRFImporter::AreaLightHeader *areaLight = new BRFImporter::AreaLightHeader[lightStruct.areaCount];
	BRFImporter::PointLightHeader *pointLight = new BRFImporter::PointLightHeader[lightStruct.pointCount];

	file.read((char*)spotLight, lightStruct.spotCount * sizeof(SpotLightHeader));
	file.read((char*)directionalLight, lightStruct.directionalCount * sizeof(DirLightHeader));
	file.read((char*)areaLight, lightStruct.areaCount * sizeof(AreaLightHeader));
	file.read((char*)pointLight, lightStruct.pointCount * sizeof(PointLightHeader));


	BRFImporter::LightData::LightData(
	*spotLight,
	*areaLight,
	*pointLight,
	*directionalLight);

	delete spotLight;
	delete directionalLight;
	delete areaLight;
	delete pointLight;

}

void BRFImporter::Fetch::MaterialData()
{

}

void BRFImporter::Fetch::GroupData()
{
}

void BRFImporter::Fetch::AttrData()
{
}

void BRFImporter::Fetch::CameraData()
{
}

void BRFImporter::Fetch::MorphAnimData()
{
}

void BRFImporter::Fetch::AnimationData()
{
}
#pragma endregion
#include "Fetch.h"

void BRFImporterLib::Fetch::LoadFile(std::string fileName)
{

	file.open("test.bin", std::ios::binary);



	if (!file.is_open())
	{
		std::cout << "Failed opening file";
	}
	else
	{
		MeshDataContainer();
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

BRFImporterLib::Fetch::Fetch()
{

}

//DECON
BRFImporterLib::Fetch::~Fetch()
{

}

#pragma region Datapassthrough
void BRFImporterLib::Fetch::MeshDataContainer()
{

	BRFImporterLib::MeshHeader meshStruct; // Meshheader struct

	//reads file according to the vertexcount.
	file.read((char*)&meshStruct.vertexCount, sizeof(meshStruct.vertexCount));
	file.read((char*)&meshStruct.indexCount, sizeof(meshStruct.indexCount));
	file.read((char*)&meshStruct.boundingBox, sizeof(meshStruct.boundingBox));

	//Calls the default constructor of vertexheader
	BRFImporterLib::VertexHeader *vertices = new BRFImporterLib::VertexHeader[meshStruct.vertexCount];
	BRFImporterLib::IndexHeader *indices = new BRFImporterLib::IndexHeader[meshStruct.indexCount];
	BRFImporterLib::OOBBHeader *boundingBox = new BRFImporterLib::OOBBHeader[meshStruct.boundingBox];

	//Read all vertices in one go
	file.read((char*)vertices, meshStruct.vertexCount *sizeof(VertexHeader));
	file.read((char*)indices, meshStruct.indexCount*sizeof(IndexHeader));
	file.read((char*)boundingBox, meshStruct.boundingBox*sizeof(OOBBHeader));

	BRFImporterLib::MeshData::MeshData(*boundingBox, *indices, *vertices);

	delete boundingBox;
	delete indices;
	delete vertices;
}

void BRFImporterLib::Fetch::SkeletonData()
{
	BRFImporterLib::SkeletonHeader skeletonStruct;

	file.read((char*)&skeletonStruct.jointCount, sizeof(skeletonStruct.jointCount));
	file.read((char*)&skeletonStruct.animationCount, sizeof(skeletonStruct.animationCount));

	BRFImporterLib::SkeletonHeader *joints = new BRFImporterLib::SkeletonHeader[skeletonStruct.jointCount];
	BRFImporterLib::SkeletonHeader *animations = new BRFImporterLib::SkeletonHeader[skeletonStruct.animationCount];


	file.read((char*)joints, skeletonStruct.jointCount * sizeof(SkeletonHeader));
	file.read((char*)animations, skeletonStruct.animationCount * sizeof(SkeletonHeader));

	delete joints;
	delete animations;

}

void BRFImporterLib::Fetch::LightData()
{
	BRFImporterLib::LightHeader lightStruct;

	file.read((char*)&lightStruct.spotCount, sizeof(lightStruct.spotCount));
	file.read((char*)&lightStruct.directionalCount, sizeof(lightStruct.directionalCount));
	file.read((char*)&lightStruct.areaCount, sizeof(lightStruct.areaCount));
	file.read((char*)&lightStruct.pointCount, sizeof(lightStruct.pointCount));

	BRFImporterLib::SpotLightHeader *spotLight = new BRFImporterLib::SpotLightHeader[lightStruct.spotCount];
	BRFImporterLib::DirLightHeader *directionalLight = new BRFImporterLib::DirLightHeader[lightStruct.directionalCount];
	BRFImporterLib::AreaLightHeader *areaLight = new BRFImporterLib::AreaLightHeader[lightStruct.areaCount];
	BRFImporterLib::PointLightHeader *pointLight = new BRFImporterLib::PointLightHeader[lightStruct.pointCount];

	file.read((char*)spotLight, lightStruct.spotCount * sizeof(SpotLightHeader));
	file.read((char*)directionalLight, lightStruct.directionalCount * sizeof(DirLightHeader));
	file.read((char*)areaLight, lightStruct.areaCount * sizeof(AreaLightHeader));
	file.read((char*)pointLight, lightStruct.pointCount * sizeof(PointLightHeader));


	BRFImporterLib::LightData::LightData(
	*spotLight,
	*areaLight,
	*pointLight,
	*directionalLight);

	delete spotLight;
	delete directionalLight;
	delete areaLight;
	delete pointLight;

}

void BRFImporterLib::Fetch::MaterialData()
{

}

void BRFImporterLib::Fetch::GroupData()
{
}

void BRFImporterLib::Fetch::AttrData()
{
}

void BRFImporterLib::Fetch::CameraData()
{
}

void BRFImporterLib::Fetch::MorphAnimData()
{
}

void BRFImporterLib::Fetch::AnimationData()
{
}
#pragma endregion
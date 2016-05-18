#include "MeshData.h"
#include <crtdbg.h>
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
using namespace BRFImporterLib;

//SETDATA
void MeshData::SetData(std::shared_ptr<MeshContainer> SrcMeshData)
{
	this->meshDataContainer = SrcMeshData;
}

//returns the meshes data.
MeshHeader* MeshData::GetMeshData()
{
	return this->meshDataContainer->meshData.get();
}

// returns the meshes vertices without skeleton data
VertexHeaderNoSkeleton MeshData::GetVertexNoSkeletonData(unsigned int vert)
{
	return this->meshDataContainer->vertexNoSkeletonData.get()[vert];
}

// returns the meshes vertices without skeleton data
VertexHeader MeshData::GetVertexData(unsigned int vert)
{
	return this->meshDataContainer->vertexData.get()[vert];
}

//returns the meshes indices.
IndexHeader MeshData::GetIndexData(unsigned int ind)
{
	return this->meshDataContainer->indexData.get()[ind];
}
//returns the meshes weights.
WeigthsHeader MeshData::GetWeightData(unsigned int vert)
{
	return this->meshDataContainer->weightData.get()[vert];
}

//CON DECON
MeshData::MeshData()
{

}
MeshData::~MeshData()
{
	//meshDataContainer.reset();
}

MeshContainer::MeshContainer(unsigned int vertexCount, unsigned int indexCount)
{
	this->meshData = std::shared_ptr<MeshHeader>(new MeshHeader);

	this->vertexNoSkeletonData = std::unique_ptr<VertexHeaderNoSkeleton[]>(new VertexHeaderNoSkeleton[vertexCount]);
	this->vertexData = std::unique_ptr<VertexHeader[]>(new VertexHeader[vertexCount]);
	this->indexData = std::unique_ptr<IndexHeader[]>(new IndexHeader[indexCount]);
	this->weightData = std::unique_ptr<WeigthsHeader[]>(new WeigthsHeader[vertexCount * 4]);
}
MeshContainer::~MeshContainer()
{
	this->meshData.reset();
	this->vertexNoSkeletonData.reset();
	this->vertexData.reset();
	this->indexData.reset();
	this->weightData.reset();
}
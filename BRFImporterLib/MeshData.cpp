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
VertexHeaderNoSkeleton* MeshData::GetVertexNoSkeletonData()
{
	return this->meshDataContainer->vertexNoSkeletonData.get();
}

// returns the meshes vertices without skeleton data
VertexHeader* MeshData::GetVertexData()
{
	return this->meshDataContainer->vertexData.get();
}

//returns the meshes indices.
IndexHeader* MeshData::GetIndexData()
{
	return this->meshDataContainer->indexData.get();
}

//CON DECON
MeshData::MeshData()
{

}
MeshData::~MeshData()
{
	meshDataContainer.reset();
}

MeshContainer::MeshContainer()
{
	this->meshData = std::shared_ptr<MeshHeader>(new MeshHeader);
	this->vertexNoSkeletonData = std::unique_ptr<VertexHeaderNoSkeleton[]>(new VertexHeaderNoSkeleton);
	this->vertexData = std::unique_ptr<VertexHeader[]>(new VertexHeader);
	this->indexData = std::unique_ptr<IndexHeader[]>(new IndexHeader);
}
MeshContainer::~MeshContainer()
{

}
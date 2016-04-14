#include "MeshData.h"
#include <crtdbg.h>
#include <memory>
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
using namespace BRFImporterLib;

//SETDATA
void MeshData::SetData(std::shared_ptr<Container> SrcMeshData)
{
	this->meshDataContainer = SrcMeshData;
	SrcMeshData.reset();
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
	return this->meshDataContainer->indexData().get();
}

//CON DECON
MeshData::MeshData()
{
	meshDataContainer(new Container);
}
MeshData::~MeshData()
{
	meshDataContainer.reset();
}
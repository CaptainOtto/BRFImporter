#include "MeshData.h"
#include <string.h>

using namespace BRFImporterLib;

//SETS
void MeshData::SetMeshData(MeshHeader* a)
{
	memcpy(this->meshData, a, sizeof(MeshHeader));
}
void MeshData::SetOOBBData(OOBBHeader* b)
{
	memcpy(this->meshData, b, sizeof(MeshHeader));
}
void MeshData::SetIndexData(IndexHeader* c)
{
	this->indexData = new IndexHeader[this->meshData->indexCount];
	memcpy(this->indexData, c,sizeof(IndexHeader) * this->meshData->indexCount);
}
void MeshData::SetVertexNoSkeletonData(VertexHeaderNoSkeleton* d)
{
	this->vertexNoSkeletonData = new VertexHeaderNoSkeleton[this->meshData->vertexCount];
	memcpy(this->vertexNoSkeletonData, d, sizeof(VertexHeaderNoSkeleton) * this->meshData->vertexCount);
}
void MeshData::SetVertexData(VertexHeader* e)
{
	this->vertexData = new VertexHeader[this->meshData->vertexCount];
	memcpy(this->vertexData, e, sizeof(VertexHeader) * this->meshData->vertexCount);
}

void MeshData::SetWeightData(WeigthsHeader* g)
{
	this->weightData = g;
}
//ENDSETS


//returns the meshes data.
MeshHeader* MeshData::GetMeshData()
{
	return this->meshData;
}

//returns the meshes boundingbox.
OOBBHeader* MeshData::GetOOBBData()
{
	return this->oobbData;
}

//returns the meshes indices.
IndexHeader* MeshData::GetIndexData()
{
	return this->indexData;
}

// returns the meshes vertices without skeleton data
VertexHeaderNoSkeleton* MeshData::GetVertexNoSkeletonData()
{
	return this->vertexNoSkeletonData;
}

//returns the meshes vertices.
VertexHeader* MeshData::GetVertexData()
{
	return this->vertexData;
}

WeigthsHeader* MeshData::GetWeightData()
{
	return this->weightData;
}



//CON DECON
MeshData::MeshData()
{

}
MeshData::~MeshData()
{
	delete meshData;
	delete oobbData;
	delete indexData;
	delete vertexNoSkeletonData;
	delete vertexData;
	delete weightData;
}
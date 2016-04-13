#include "MeshData.h"
using namespace BRFImporterLib;

//SETS
void MeshData::setMeshData(MeshHeader* a)
{
	this->meshData = a;
}
void MeshData::setOOBBData(OOBBHeader b)
{
	this->oobbData = b;
}
void MeshData::setIndexData(IndexHeader* c)
{
	this->indexData = c;
}
void MeshData::setVertexNoSkeletonData(VertexHeaderNoSkeleton* d)
{
	this->VertexNoSkeletonData = d;
}
void MeshData::setVertexData(VertexHeader* e)
{
	this->vertexData = e;
}

void MeshData::setWeightData(WeigthsHeader* g)
{
	this->weightData = g;
}
//ENDSETS


//returns the meshes data.
MeshHeader* MeshData::getMeshData()
{
	return this->meshData;
}

//returns the meshes boundingbox.
OOBBHeader MeshData::getOOBBData()
{
	return this->oobbData;
}

//returns the meshes indices.
IndexHeader* MeshData::getIndexData()
{
	return this->indexData;
}

// returns the meshes vertices without skeleton data
VertexHeaderNoSkeleton* MeshData::getVertexNoSkeletonData()
{
	return this->VertexNoSkeletonData;
}

//returns the meshes vertices.
VertexHeader* MeshData::getVertexData()
{
	return this->vertexData;
}

WeigthsHeader* MeshData::getWeightData()
{
	return this->weightData;
}



//CON DECON
MeshData::MeshData()
{

}
MeshData::~MeshData()
{

}
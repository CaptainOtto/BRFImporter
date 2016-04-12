#include "MeshData.h"
using namespace BRFImporterLib;

//returns the meshes data.
MeshHeader MeshData::getMeshData()
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
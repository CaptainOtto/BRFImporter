#include "MeshData.h"
using namespace BRFImporterLib;

//returns the meshes data.
MeshHeader MeshData::getMeshData()
{
	return this->meshContent;
}

//returns the meshes boundingbox.
OOBBHeader MeshData::getOOBBData()
{
	return this->oobbContent;
}

//returns the meshes indices.
std::vector<IndexHeader>* MeshData::getIndexData()
{
	return &this->indexContent;
}

//returns the meshes vertices.
std::vector<VertexHeader>* MeshData::getVertexData()
{
	return &this->vertexContent;
}
// ---II--- with animation
std::vector<AniVertexHeader>* MeshData::getAniVertexData()
{
	return &this->aniVertexContent;
}

//CON DECON
MeshData::MeshData()
{

}

MeshData::~MeshData()
{

}
#include "MeshData.h"
using namespace BRFImporterLib;

//returns the meshes data.
MeshHeader MeshData::meshContent()
{
	return this->meshContent;
}

//returns the meshes boundingbox.
OOBBHeader MeshData::oobbContent()
{
	return this->oobbContent;
}

//returns the meshes indices.
std::vector<IndexHeader> MeshData::indexContent()
{
	return this->indexContent;
}

//returns the meshes vertices.
std::vector<VertexHeader> MeshData::vertexContent()
{
	return this->vertexContent;
}

//CON DECON
MeshData::MeshData()
{

}

MeshData::~MeshData()
{

}
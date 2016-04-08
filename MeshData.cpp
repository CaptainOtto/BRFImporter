#include "MeshData.h"

BRFImporter::OOBBHeader BRFImporter::MeshData::OOBBData()
{
	return this->oobbData;
}
BRFImporter::IndexHeader BRFImporter::MeshData::IndexData()
{
	return this->indexData;
}
BRFImporter::VertexHeader BRFImporter::MeshData::VertexData()
{
	return this->vertexData;
}

//CON
BRFImporter::MeshData::MeshData(
	OOBBHeader OOBBData,
	IndexHeader IndexData,
	VertexHeader VertexData
	)
{
	this->oobbData = OOBBData;
	this->indexData = IndexData;
	this->vertexData = VertexData;
}
//DECON
BRFImporter::MeshData::~MeshData()
{

}

#include "MeshData.h"

BRFImporter::OOBBHeader BRFImporter::MeshData::oobbData()
{
	return this->oobbData;
}
BRFImporter::IndexHeader BRFImporter::MeshData::indexData()
{
	return this->indexData;
}
BRFImporter::VertexHeader BRFImporter::MeshData::vertexData()
{
	return this->vertexData;
}

//CON
BRFImporter::MeshData::MeshData(OOBBHeader OOBBData, IndexHeader IndexData, VertexHeader VertexData)
{
	this->oobbData = OOBBData;
	this->indexData = IndexData;
	this->vertexData = VertexData;
}
//DECON
BRFImporter::MeshData::~MeshData()
{
	//test
}



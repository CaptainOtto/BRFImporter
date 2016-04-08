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
//BRFImporter::WeigthsHeader BRFImporter::MeshData::weightsData()
//{
//	return this->weightData;
//}

//CON
BRFImporter::MeshData::MeshData(
	OOBBHeader OOBBData,
	IndexHeader IndexData,
	VertexHeader VertexData
	/*WeigthsHeader weightData*/)
{
	this->oobbData = OOBBData;
	this->indexData = IndexData;
	this->vertexData = VertexData;
	//this->weightData = weightData;
}
//DECON
BRFImporter::MeshData::~MeshData()
{

}

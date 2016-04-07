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

<<<<<<< HEAD
//CON
BRFImporter::MeshData::MeshData(OOBBHeader OOBBData, IndexHeader IndexData, VertexHeader VertexData)
=======
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
>>>>>>> refs/remotes/origin/Otto-branch
{
	this->oobbData = OOBBData;
	this->indexData = IndexData;
	this->vertexData = VertexData;
<<<<<<< HEAD
=======
	//this->weightData = weightData;
>>>>>>> refs/remotes/origin/Otto-branch
}
//DECON
BRFImporter::MeshData::~MeshData()
{
<<<<<<< HEAD

}


=======
	
}
>>>>>>> refs/remotes/origin/Otto-branch

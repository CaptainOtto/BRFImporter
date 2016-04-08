#include "MeshData.h"
using namespace BRFImporterLib;
//FUNCTION DEFINITIONS FOR MESHDATA
int MeshData::getA()
{
	return this->A;
}
int MeshData::getB()
{
	return this->B;
}
MeshData::MeshData()
{
	this->B = 2;
}

MeshData::~MeshData()
{
	Fetch::~Fetch();
}
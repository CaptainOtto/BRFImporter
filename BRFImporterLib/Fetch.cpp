#include "Fetch.h"
using namespace BRFImporterLib;
//FUNCTION DEFINITIONS FOR FETCH

MeshData Fetch::getMesh(unsigned meshID)
{
	if (meshID <= meshAmount.size())
	{
		return this->meshAmount.at(meshID);
	}
	else
	{
		//break
	}
	
}
Fetch::Fetch()
{

}
Fetch::~Fetch()
{

}
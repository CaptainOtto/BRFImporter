#include "Fetch.h"
#include "FileData.h"
using namespace BRFImporterLib;

//SETS
void Fetch::setMain(MainHeader* mainDataptr)
{
	this->mainheader = mainDataptr;
}
void Fetch::setMeshes(MeshData* meshDataptr)
{
	this->meshes = meshDataptr;
}
void Fetch::setLights(LightData* lightDataptr)
{
	this->lights = lightDataptr;
}

//returns the mainheader info
MainHeader * BRFImporterLib::Fetch::getMain()
{
	return this->mainheader;
}
//returns a whole mesh from an array using its ID
MeshData* Fetch::getMesh(unsigned int meshID)
{
	if (meshID > mainheader->meshAmount)
	{
		return nullptr;
	}
	else
	{
		for (unsigned int i = 0; i <= mainheader->meshAmount; i++)
		{
			if (meshID == meshes[i].getMeshData()->objectID)
			{
				return &meshes[i];
			}
		}
		return nullptr;
	}
}
//returns a light from an array using its ID
LightData* Fetch::getLight(unsigned int lightID)
{

	unsigned int lightAmt = 0;
	lightAmt += lights->getLightData().areaCount;
	lightAmt += lights->getLightData().directionalCount;
	lightAmt += lights->getLightData().pointCount;
	lightAmt += lights->getLightData().spotCount;

	if (lightID > lightAmt)
	{
		return nullptr;
	}
	else
	{
		for (unsigned int i = 0; i <= lightAmt; i++)
		{
			if (lightID == lights->getAreaLightData()->objectID)
			{
				return &lights[i];
			}
			if (lightID == lights->getDirLightData()->objectID)
			{
				return &lights[i];
			}
			if (lightID == lights->getPointLightData()->objectID)
			{
				return &lights[i];
			}
			if (lightID == lights->getSpotLightData()->objectID)
			{
				return &lights[i];
			}
		}
		return nullptr;
	}
}
Fetch::Fetch()
{

}
Fetch::~Fetch()
{
	
}


//int main()
//{
//	//FUNC TESTS
//	FileData player;
//	std::string filename = "filename.brf";
//	player.LoadFile(filename, true, false);
//	float x = player.fetch.getMesh(3)->getVertexData()->pos[1];
//
//	
//}

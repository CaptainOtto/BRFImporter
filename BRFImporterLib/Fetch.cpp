#include "Fetch.h"
#include "FileData.h"
#include <crtdbg.h>
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
using namespace BRFImporterLib;

//returns the mainheader info
MainHeader*  BRFImporterLib::Fetch::Main()
{
	return this->mainheader;
}
//returns a whole mesh from an array using its ID
MeshData* Fetch::Mesh(unsigned int meshID)
{
	if (meshID > this->mainheader->meshAmount)
	{
		return nullptr;
	}
	else
	{
		for (unsigned int i = 0; i < (this->mainheader->meshAmount); i++)
		{
			if (meshID == this->meshes[i].GetMeshData()->objectID)
			{
				return &meshes[i];
			}
		}
		return nullptr;
	}
}
//returns a light from an array using its ID
LightData* Fetch::Light(unsigned int lightID)
{

	unsigned int lightAmt = 0;
	lightAmt += lights->GetLightData().areaCount;
	lightAmt += lights->GetLightData().directionalCount;
	lightAmt += lights->GetLightData().pointCount;
	lightAmt += lights->GetLightData().spotCount;

	if (lightID > lightAmt)
	{
		return nullptr;
	}
	else
	{
		for (unsigned int i = 0; i <= lightAmt; i++)
		{
			if (lightID == lights->GetAreaLightData()->objectID)
			{
				return &lights[i];
			}
			if (lightID == lights->GetDirLightData()->objectID)
			{
				return &lights[i];
			}
			if (lightID == lights->GetPointLightData()->objectID)
			{
				return &lights[i];
			}
			if (lightID == lights->GetSpotLightData()->objectID)
			{
				return &lights[i];
			}
		}
		return nullptr;
	}
}

//CON DECON
Fetch::Fetch(MainHeader* a, MeshData* b)
{
	this->mainheader = new MainHeader;
	memcpy(this->mainheader, a, sizeof(MainHeader));
	this->meshes = new MeshData[mainheader->meshAmount];
	memcpy(this->meshes, b, sizeof(MeshData) * this->mainheader->meshAmount);
}
Fetch::Fetch()
{

}
Fetch::~Fetch()
{
	delete[] this->meshes;
	delete this->mainheader;
}

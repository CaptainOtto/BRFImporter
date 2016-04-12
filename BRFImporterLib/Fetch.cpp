#include "Fetch.h"
using namespace BRFImporterLib;

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
			if (meshID == meshes[i].getMeshData().objectID)
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
//	Fetch data;
//	VertexHeader*	 test1 = data.getMesh(3)->getVertexData();
//	IndexHeader*	 test2 = data.getMesh(3)->getIndexData();
//	MeshData*		 test3 = data.getMesh(2);
//
//	VertexHeader	 test4;
//	VertexHeader*	 test5;
//	double pos_test1 = test4.pos[1];
//	double pos_test2 = test5->pos[1];
//}

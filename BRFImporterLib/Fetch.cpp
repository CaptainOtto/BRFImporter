#include "Fetch.h"
using namespace BRFImporterLib;

//returns a whole mesh from an array using its position as ID
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

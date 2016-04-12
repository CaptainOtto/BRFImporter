#include "Fetch.h"
#include <assert.h>
using namespace BRFImporterLib;

//returns a whole mesh from an array using its position as ID
MeshData* Fetch::getMesh(unsigned int meshID)
{

	assert(meshID < mainheader.meshAmount);

	for (int i = 0; i <= mainheader.meshAmount; i++)
	{
		if (meshID == meshes[i].getMeshData().objectID)
		{
			return &meshes[i];
		}
	}
}
Fetch::Fetch()
{

}
Fetch::~Fetch()
{

}


int main()
{
	Fetch data;
	VertexHeader* test = data.getMesh(3)->getVertexData();
	IndexHeader* test2 = data.getMesh(3)->getIndexData();
	MeshData* test3 = data.getMesh(2);
	VertexHeader test4;
	double postest1 = test4.pos[1];
	double postest2 = test->pos[1];
}

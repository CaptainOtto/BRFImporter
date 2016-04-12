#pragma once
#include "BRFImporterStructs.h"

namespace BRFImporterLib
{
	class MeshData
	{
	protected:
		MeshHeader meshData;
		OOBBHeader oobbData;
		IndexHeader* indexData;
		VertexHeaderNoSkeleton* VertexNoSkeletonData;
		VertexHeader* vertexData;
		WeigthsHeader* weightData;
	public:
		MeshHeader getMeshData();
		OOBBHeader getOOBBData();
		IndexHeader* getIndexData();
		VertexHeaderNoSkeleton* getVertexNoSkeletonData();
		VertexHeader* getVertexData();
		WeigthsHeader* getWeightData();

		//CON DECON
		MeshData();
		~MeshData();
	};
}
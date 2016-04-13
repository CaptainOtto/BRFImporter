#pragma once
#include "BRFImporterStructs.h"

namespace BRFImporterLib
{
	class MeshData
	{
	protected:
		MeshHeader* meshData;
		OOBBHeader oobbData;
		IndexHeader* indexData;
		VertexHeaderNoSkeleton* VertexNoSkeletonData;
		VertexHeader* vertexData;
		WeigthsHeader* weightData;
	public:
		void setMeshData(MeshHeader* a);
		void setOOBBData(OOBBHeader b);
		void setIndexData(IndexHeader* c);
		void setVertexNoSkeletonData(VertexHeaderNoSkeleton* d);
		void setVertexData(VertexHeader* e);
		void setWeightData(WeigthsHeader* g);

		MeshHeader* getMeshData();
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
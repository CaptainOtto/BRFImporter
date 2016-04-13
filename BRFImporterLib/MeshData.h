#pragma once
#include "BRFImporterStructs.h"

namespace BRFImporterLib
{
	//per mesh
	class MeshData
	{
	protected:
		MeshHeader* meshData;
		OOBBHeader* oobbData;
		IndexHeader* indexData;
		VertexHeaderNoSkeleton* vertexNoSkeletonData;
		VertexHeader* vertexData;
		WeigthsHeader* weightData;
	public:
		void SetMeshData(MeshHeader* a);
		void SetOOBBData(OOBBHeader* b);
		void SetIndexData(IndexHeader* c);
		void SetVertexNoSkeletonData(VertexHeaderNoSkeleton* d);
		void SetVertexData(VertexHeader* e);
		void SetWeightData(WeigthsHeader* g);

		MeshHeader* GetMeshData();
		OOBBHeader* GetOOBBData();
		IndexHeader* GetIndexData();
		VertexHeaderNoSkeleton* GetVertexNoSkeletonData();
		VertexHeader* GetVertexData();
		WeigthsHeader* GetWeightData();

		//CON DECON
		MeshData();
		~MeshData();
	};
}
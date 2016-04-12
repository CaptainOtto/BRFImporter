#pragma once
#include <vector>
#include "BRFImporterStructs.h"

namespace BRFImporterLib
{
	class MeshData
	{
	protected:
		MeshHeader meshData;
		OOBBHeader oobbData;
		IndexHeader* indexData;
		VertexHeader* vertexData;
		VertexHeaderNoSkeleton* VertexNoSkeletonData;
	public:
		MeshHeader getMeshData();
		OOBBHeader getOOBBData();
		IndexHeader* getIndexData();
		VertexHeader* getVertexData();
		VertexHeaderNoSkeleton* getVertexNoSkeletonData();

		//CON DECON
		MeshData();
		~MeshData();
	};




}
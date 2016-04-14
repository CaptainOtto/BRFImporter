#pragma once
#include "BRFImporterStructs.h"

namespace BRFImporterLib
{	
	struct Container
	{
		std::shared_ptr<MeshHeader> meshData;
		std::unique_ptr<VertexHeaderNoSkeleton[]> vertexNoSkeletonData;
		std::unique_ptr<VertexHeader[]> vertexData;
		std::unique_ptr<IndexHeader[]> indexData;
	};
	class MeshData
	{
	protected:
		std::shared_ptr<Container> meshDataContainer;
	public:
		void SetData(std::shared_ptr<Container> SrcMeshData);


		MeshHeader* GetMeshData();
		VertexHeaderNoSkeleton* GetVertexNoSkeletonData();
		VertexHeader* GetVertexData();
		IndexHeader* GetIndexData();
		//CON DECON
		MeshData();
		~MeshData();
	};
}
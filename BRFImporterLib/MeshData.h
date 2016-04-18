#pragma once
#include <memory>
#include "BRFImporterStructs.h"

namespace BRFImporterLib
{	
	class MeshContainer
	{
	public:
		std::shared_ptr<MeshHeader> meshData;
		std::unique_ptr<VertexHeaderNoSkeleton[]> vertexNoSkeletonData;
		std::unique_ptr<VertexHeader[]> vertexData;
		std::unique_ptr<IndexHeader[]> indexData;
		MeshContainer();
		~MeshContainer();

	};
	class MeshData
	{
	protected:
		std::shared_ptr<MeshContainer> meshDataContainer;
	public:
		void SetData(std::shared_ptr<MeshContainer> SrcMeshData);


		MeshHeader* GetMeshData();
		VertexHeaderNoSkeleton* GetVertexNoSkeletonData();
		VertexHeader* GetVertexData();
		IndexHeader* GetIndexData();
		//CON DECON
		MeshData();
		~MeshData();
	};
}
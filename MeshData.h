#pragma once
#include "Fetch.h"

namespace BRFImporterLib
{
	class MeshData : Fetch
	{
	protected:
		BRFImporterLib::OOBBHeader *oobbData;
		BRFImporterLib::IndexHeader *indexData;
		BRFImporterLib::VertexHeader *vertexData;
	private:
		MeshData();
	public:
		BRFImporterLib::OOBBHeader OOBBData();
		BRFImporterLib::IndexHeader IndexData();
		BRFImporterLib::VertexHeader VertexData();

		MeshData(
			OOBBHeader *OOBBData,
			IndexHeader *IndexData,
			VertexHeader *VertexData
			);
		~MeshData();
	};
}
#pragma once
#include "Fetch.h"

namespace BRFImporter
{
	class MeshData : Fetch
	{
	protected:
		BRFImporter::OOBBHeader oobbData;
		BRFImporter::IndexHeader *indexData;
		BRFImporter::VertexHeader *vertexData;
	private:
		MeshData();
	public:
		BRFImporter::OOBBHeader OOBBData();
		BRFImporter::IndexHeader IndexData();
		BRFImporter::VertexHeader VertexData();

		MeshData(
			OOBBHeader OOBBData,
			IndexHeader *IndexData,
			VertexHeader *VertexData
			);
		~MeshData();
	};
}
#pragma once
#include "Fetch.h"
#include "BRFImporterStructs.h"

namespace BRFImporter
{
	class MeshData : Fetch
	{
	protected:
		MeshHeader meshData;
		OOBBHeader OOBBData;
		IndexHeader IndexData;
		VertexHeader VertexData;
	private:
		MeshData();
	public:
		OOBBHeader OOBBData();
		void IndexData();
		void VertexData();

		MeshData(OOBBHeader OOBBData, IndexHeader IndexData, VertexHeader VertexData);
		
		~MeshData();

	};
}
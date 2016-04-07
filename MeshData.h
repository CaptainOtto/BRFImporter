#pragma once
#include "Fetch.h"

namespace BRFImporter
{
	class MeshData : Fetch
	{

	protected:
		BRFImporter::OOBBHeader oobbData;
		BRFImporter::IndexHeader indexData;
		BRFImporter::VertexHeader vertexData;
		BRFImporter::WeigthsHeader weightData;
	private:


	public:
		BRFImporter::OOBBHeader oobbData();
		BRFImporter::IndexHeader indexData();
		BRFImporter::VertexHeader vertexData();
		//BRFImporter::WeigthsHeader weightsData();

		MeshData(
			OOBBHeader OOBBData,
			IndexHeader IndexData,
			VertexHeader VertexData/*,
			WeigthsHeader weightData*/);

		~MeshData();
	};
}
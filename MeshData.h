#pragma once
#include "Fetch.h"

namespace BRFImporter
{
	class MeshData : Fetch
	{
<<<<<<< HEAD
=======

>>>>>>> refs/remotes/origin/Otto-branch
	protected:
		BRFImporter::OOBBHeader oobbData;
		BRFImporter::IndexHeader indexData;
		BRFImporter::VertexHeader vertexData;
<<<<<<< HEAD
	private:
		MeshData();
=======
		BRFImporter::WeigthsHeader weightData;
	private:


>>>>>>> refs/remotes/origin/Otto-branch
	public:
		BRFImporter::OOBBHeader oobbData();
		BRFImporter::IndexHeader indexData();
		BRFImporter::VertexHeader vertexData();
<<<<<<< HEAD
=======
		//BRFImporter::WeigthsHeader weightsData();

		MeshData(
			OOBBHeader OOBBData,
			IndexHeader IndexData,
			VertexHeader VertexData/*,
			WeigthsHeader weightData*/);
>>>>>>> refs/remotes/origin/Otto-branch

		MeshData(OOBBHeader OOBBData, IndexHeader IndexData, VertexHeader VertexData);
		
		~MeshData();
	};
}
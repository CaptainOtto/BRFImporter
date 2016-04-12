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
		AniVertexHeader* aniVertexData;
	public:
		MeshHeader getMeshData();
		OOBBHeader getOOBBData();
		IndexHeader* getIndexData();
		VertexHeader* getVertexData();
		AniVertexHeader* getAniVertexData();

		//CON DECON
		MeshData();
		~MeshData();
	};




}
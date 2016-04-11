#pragma once
#include <vector>
#include "BRFImporterStructs.h"

namespace BRFImporterLib
{
	class MeshData
	{
	protected:
		MeshHeader meshContent;
		OOBBHeader oobbContent;
		std::vector<IndexHeader> indexContent;
		std::vector<VertexHeader> vertexContent;
		std::vector<AniVertexHeader> aniVertexContent;
	public:
		//returns mesh data
		MeshHeader getMeshData();
		//Returns bBox data
		OOBBHeader getOOBBData();
		//Returns index data
		std::vector<IndexHeader>* getIndexData();
		//Returns vertex data
		std::vector<VertexHeader>* getVertexData();
		std::vector<AniVertexHeader>* getAniVertexData();
		//CON DECON
		MeshData();
		~MeshData();
	};




}
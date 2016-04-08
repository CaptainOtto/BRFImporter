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
	public:
		//get data funcs!!!
		//returns all idices:
		MeshHeader meshContent();
		OOBBHeader oobbContent();
		std::vector<IndexHeader>* indexContent();
		std::vector<VertexHeader>* vertexContent();
		//CON DECON
		MeshData();
		~MeshData();
	};




}
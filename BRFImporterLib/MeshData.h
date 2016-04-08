#pragma once
#include "FileData.h"

namespace BRFImporterLib
{
	class MeshData : FileData
	{
	protected:
		MeshHeader meshContent;
		OOBBHeader oobbContent;
		std::vector<IndexHeader> indexContent;
		std::vector<VertexHeader> vertexContent;
	public:

		//CON DECON
		MeshData();
		~MeshData();
	};




}
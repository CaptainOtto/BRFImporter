#pragma once
#include <string>
#include "BRFImporterStructs.h"

namespace BRFImporterLib
{
	class FileData
	{
	protected:
		MeshHeader meshContent;
		OOBBHeader oobbContent;
		IndexHeader indexContent;
		VertexHeader vertexContent;
	
	public:
		void LoadFile(std::string fileName);

		//CON DECON
		FileData();
		~FileData();
	};
}
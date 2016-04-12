#pragma once
#include <string>
#include <fstream>
#include "MeshData.h"
#include "BRFImporterStructs.h"


namespace BRFImporterLib
{
	class FileData
	{
	protected:
	public:
		void LoadFile(std::string fileName, bool mesh, bool light);
		void LoadMesh(std::ifstream *inFile);
		void LoadLight(std::ifstream *inFile);

		
		//CON DECON
		FileData();
		~FileData();
	};
}
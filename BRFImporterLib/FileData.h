#pragma once
#include <string>
#include "MeshData.h"


namespace BRFImporterLib
{
	class MeshData;
	class FileData
	{
	protected:
	public:
		void LoadFile(std::string fileName);

		//CON DECON
		FileData();
		~FileData();
	};
}
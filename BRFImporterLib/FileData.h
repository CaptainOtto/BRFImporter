#pragma once
#include <string>
#include "MeshData.h"


namespace BRFImporterLib
{
	class MeshData;
	class FileData
	{

	protected:
		std::vector<MeshData> meshContainer;

		//all headers here
		//as pointers?
	
	public:
		void LoadFile(std::string fileName);

		//CON DECON
		FileData();
		~FileData();
	};
}
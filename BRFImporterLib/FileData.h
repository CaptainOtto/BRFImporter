#pragma once
#include <string>
#include <vector>
#include "BRFImporterStructs.h"
class MeshData;
namespace BRFImporterLib
{
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
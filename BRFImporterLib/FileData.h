#pragma once
#include <string>
#include <fstream>


namespace BRFImporterLib
{
	class FileData
	{
	public:
		void LoadFile(std::string fileName);

		//CON DECON
		FileData();
		~FileData();
	};
}
#pragma once
#include <string>

namespace BRFImporter
{
	class BRFImporterClass
	{
	protected:
		//std::string filePath;
		//std::string fileName;
	private:
		//CON
		BRFImporterClass();
	public:
		//void setFilePath(std::string filePath);
		//std::string getFileName();
		
		//CON
		BRFImporterClass(std::string fileName);
		
		//DECON
		~BRFImporterClass();
	};
}
#pragma once
#include <string>

namespace BRFImporter
{
	class BRFImporterClass
	{
	protected:
		//std::string filePath;
		//std::string fileName;
		BRFImporterClass();
	private:

	public:
		//void setFilePath(std::string filePath);
		//std::string getFileName();
		
		//CON
		BRFImporterClass(std::string fileName);
		
		//DECON
		~BRFImporterClass();
	};
}
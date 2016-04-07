#pragma once

namespace BRFImporter
{
	class BRFImporterClass
	{
	protected:
		char filePath[256];
		char fileName[256];
	public:
		void setFilePath(char filePath[]);
		char getFileName();
		
		//CON
		BRFImporterClass(char fileName[]);
		BRFImporterClass();
		//DECON
		~BRFImporterClass();
	};
}
#pragma once
#include <string>
#include <fstream>
#include "Fetch.h"
#include "BRFImporterStructs.h"


namespace BRFImporterLib
{
	class FileData
	{
	protected:
		void LoadMain(Fetch Fetch, std::ifstream *inFile);
		void LoadMesh(Fetch Fetch, std::ifstream *inFile);
		void LoadLight(Fetch Fetch, std::ifstream *inFile);
	public:
		//MORE BOOLS, -50 DKP!
		void LoadFile(Fetch Fetch, std::string fileName, bool mesh, bool light);


		
		//CON DECON
		FileData();
		~FileData();
	};
}
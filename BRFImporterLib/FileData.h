#pragma once
#include <string>
#include <fstream>
#include <memory>
#include "Fetch.h"
#include "BRFImporterStructs.h"


namespace BRFImporterLib
{
	class FileData
	{
	protected:
		//MeshBlock
		MainHeader* tempMain;
		MeshData* meshArray;

		//funcBlock
		void LoadMain(std::ifstream *inFile);
		void LoadMesh(std::ifstream *inFile);

	public:
		Fetch* fetch;

		//takes a string filename and what specific parts of the file to read.
		void LoadFile(std::string fileName, bool mesh);

		//CON DECON
		FileData();
		~FileData();
	};
}
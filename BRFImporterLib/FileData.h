#pragma once
#include <string>
#include <fstream>
#include "Fetch.h"

namespace BRFImporterLib
{
	class FileData
	{
	protected:
		//funcBlock
		void LoadMain(std::shared_ptr<MainHeader> tempMain, std::ifstream *inFile);
		void LoadMesh(std::vector<std::shared_ptr<MeshData>> meshVector, std::shared_ptr<MainHeader> tempMain, std::ifstream *inFile);

	public:
		std::shared_ptr<Fetch> fetch;

		//takes a string filename and what specific parts of the file to read.
		void LoadFile(std::string fileName, bool mesh);

		//CON DECON
		FileData();
		~FileData();
	};
}
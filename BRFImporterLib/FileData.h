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
		//MeshBlock
		MainHeader mainStruct;
		MeshData thisMesh;
		MeshHeader* meshStruct;
		VertexHeader* vertices;
		IndexHeader* indices;

		//funcBlock
		void LoadMain(std::ifstream *inFile);
		void LoadMesh(std::ifstream *inFile);
		void LoadLight(std::ifstream *inFile);
	public:
		Fetch fetch;
		//MORE BOOLS, -50 DKP!
		void LoadFile(std::string fileName, bool mesh, bool light);


		
		//CON DECON
		FileData();
		~FileData();
	};
}
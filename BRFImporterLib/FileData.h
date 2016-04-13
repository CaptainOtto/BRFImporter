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
		
		void LoadMain(std::ifstream *inFile);
		void LoadMesh(std::ifstream *inFile);
		void LoadLight(std::ifstream *inFile);

		//MeshBlock
		MainHeader mainStruct;
		MeshData thisMesh;
		MeshHeader* meshStruct;
		VertexHeader* vertices;
		IndexHeader* indices;
	public:
		Fetch fetch;
		//MORE BOOLS, -50 DKP!
		void LoadFile(std::string fileName, bool mesh, bool light);


		
		//CON DECON
		FileData();
		~FileData();
	};
}
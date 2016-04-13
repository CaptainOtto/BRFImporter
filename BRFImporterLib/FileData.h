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
		MeshData* thisMesh;
		LightData* thisLight;

		MeshHeader* meshStruct;
		VertexHeader* vertices;
		VertexHeaderNoSkeleton* verticesNoSkeleton;
		IndexHeader* indices;

		//funcBlock
		void LoadMain(std::ifstream *inFile);
		void LoadMesh(std::ifstream *inFile);
		void LoadLight(std::ifstream *inFile);

		MainHeader Mainreturner() { return this->mainStruct; };
		MeshData* Meshreturner() { return this->thisMesh; };
		LightData* Lightreturner() { return this->thisLight; };
	public:
		Fetch* fetch;

		//takes a string filename and what specific parts of the file to read.
		void LoadFile(std::string fileName, bool mesh, bool light);

		//CON DECON
		FileData();
		~FileData();
		friend Fetch;
	};
}
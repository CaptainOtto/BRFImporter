#pragma once
#include "MeshData.h"
#include "LightData.h"

namespace BRFImporterLib
{
	
	class Fetch
	{
	
	private:
		MainHeader* mainheader;
		MeshData* meshes;
		LightData* lights;
	public:
		MainHeader* Main();
		MeshData* Mesh(unsigned int meshID);
		LightData* Light(unsigned int lightID);

		//CON DECON
		Fetch();
		~Fetch();
		
	};
}

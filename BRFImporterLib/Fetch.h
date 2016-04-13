#pragma once
#include "MeshData.h"
#include "LightData.h"

namespace BRFImporterLib
{
	class Fetch
	{
	protected:
		MainHeader* mainheader;
		MeshData* meshes;
		LightData* lights;
	public:
		void setMain(MainHeader* mainDataptr);
		void setMeshes(MeshData* meshDataptr);
		void setLights(LightData* lightDataptr);
		MeshData* getMesh(unsigned int meshID);
		LightData* getLight(unsigned int lightID);

		//CON DECON
		Fetch();
		~Fetch();
	};
}

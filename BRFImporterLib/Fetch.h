#pragma once
#include "MeshData.h"

namespace BRFImporterLib
{
	class Fetch
	{
	protected:
		MainHeader mainheader;
		MeshData* meshes;
		//LightData* lights;
	public:
		MeshData* getMesh(unsigned int meshID);
		//LightData* getLight(unsigned lightID);
		//CON DECON
		Fetch();
		~Fetch();
	};




}

//meshammount.resize (meshcount från mainheader)
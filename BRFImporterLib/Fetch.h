#pragma once
#include "MeshData.h"

namespace BRFImporterLib
{
	class Fetch
	{
	protected:
		MainHeader* mainheader;
		MeshData* meshes;
	public:
		MeshData* getMesh(unsigned int meshID);

		//CON DECON
		Fetch();
		~Fetch();
	};




}

//meshammount.resize (meshcount från mainheader)
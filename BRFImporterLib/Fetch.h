#pragma once
#include "MeshData.h"

namespace BRFImporterLib
{
	class Fetch
	{
	protected:
		std::vector<MeshData> meshAmount;
	public:
		MeshData getMesh(unsigned meshID);
		//CON DECON
		Fetch();
		~Fetch();
	};




}

//meshammount.resize (meshcount från mainheader)
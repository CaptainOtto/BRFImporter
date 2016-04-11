#pragma once
#include "MeshData.h"

namespace BRFImporterLib
{
	class Fetch
	{
	protected:
		std::vector<MeshData> meshAmount;
		std::vector<LightHeader> lightAmount;
	public:
		MeshData getMesh(unsigned meshID);
		LightData getLight(unsigned lightID);
		//CON DECON
		Fetch();
		~Fetch();
	};




}

//meshammount.resize (meshcount från mainheader)
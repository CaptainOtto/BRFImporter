#pragma once
#include "BRFImporterStructs.h"

namespace BRFImporterLib
{
	class LightData
	{
	protected:
		LightHeader lightData;
		SpotLightHeader* spotLightData;
		AreaLightHeader* areaLightData;
		PointLightHeader* pointLightData;
		DirLightHeader* dirLightData;
	public:
		LightHeader getLightData();
		SpotLightHeader* getSpotLightData();
		AreaLightHeader* getAreaLightData();
		PointLightHeader* getPointLightData();
		DirLightHeader* getDirLightData();

		//CON DECON
		LightData();
		~LightData();
	};
}
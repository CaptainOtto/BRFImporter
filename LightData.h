#pragma once
#include "Fetch.h"

namespace BRFImporter
{
	class LightData : Fetch
	{
	protected:
		BRFImporter::SpotLightHeader spotLightData;
		BRFImporter::AreaLightHeader areaLightData;
		BRFImporter::PointLightHeader pointLightData;
		BRFImporter::DirLightHeader dirLightData;
	private:
		LightData();
	public:
		BRFImporter::SpotLightHeader SpotLightData();

		BRFImporter::AreaLightHeader AreaLightData();

		BRFImporter::PointLightHeader PointLightData();

		BRFImporter::DirLightHeader DirLightData();

		LightData(
			SpotLightHeader spotLightData,
			AreaLightHeader areaLightData,
			PointLightHeader pointLightData,
			DirLightHeader dirLightData);

		~LightData();
	};
}
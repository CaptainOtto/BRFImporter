#pragma once
#include "Fetch.h"

namespace BRFImporter
{
	class LightData : Fetch
	{
	protected:
		BRFImporter::SpotLightHeader spotLightData;
		BRFImporter::AmbLightHeader ambLightData;
		BRFImporter::AreaLightHeader areaLightData;
		BRFImporter::PointLightHeader pointLightData;
		BRFImporter::DirLightHeader dirLightData;
	private:
		LightData();
	public:
		BRFImporter::SpotLightHeader SpotLightData();

		BRFImporter::AmbLightHeader AmbLightData();

		BRFImporter::AreaLightHeader AreaLightData();

		BRFImporter::PointLightHeader PointLightData();

		BRFImporter::DirLightHeader DirLightData();

		LightData(
			SpotLightHeader spotLightData,
			AmbLightHeader ambLightData,
			AreaLightHeader areaLightData,
			PointLightHeader pointLightData,
			DirLightHeader dirLightData);

		~LightData();
	};
}
#pragma once
#include "Fetch.h"

namespace BRFImporter
{
	class LightData : Fetch
	{
	protected:
		BRFImporter::SpotLightHeader spotLightData;
<<<<<<< HEAD
		BRFImporter::AmbLightHeader ambLightData;
=======
>>>>>>> refs/remotes/origin/Otto-branch
		BRFImporter::AreaLightHeader areaLightData;
		BRFImporter::PointLightHeader pointLightData;
		BRFImporter::DirLightHeader dirLightData;
	private:
		LightData();
	public:
		BRFImporter::SpotLightHeader SpotLightData();

<<<<<<< HEAD
		BRFImporter::AmbLightHeader AmbLightData();
=======
>>>>>>> refs/remotes/origin/Otto-branch

		BRFImporter::AreaLightHeader AreaLightData();

		BRFImporter::PointLightHeader PointLightData();

		BRFImporter::DirLightHeader DirLightData();

		LightData(
			SpotLightHeader spotLightData,
<<<<<<< HEAD
			AmbLightHeader ambLightData,
=======
>>>>>>> refs/remotes/origin/Otto-branch
			AreaLightHeader areaLightData,
			PointLightHeader pointLightData,
			DirLightHeader dirLightData);

		~LightData();
	};
}
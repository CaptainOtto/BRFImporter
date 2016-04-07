#pragma once
#include "BRFImporterClass.h"

namespace BRFImporter
{
	class Fetch : BRFImporterClass
	{
	private:


	public:
		void MeshData();
		void MaterialData();
		void SkeletonData();
		void GroupData();
		void LightData();
		void AttrData();
		void CameraData();
		void MorphAnimData();
		void AnimationData();

		Fetch(std::string fileName);
		Fetch();
		~Fetch();

	};
}
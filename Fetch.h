#pragma once
#include "BRFImporterClass.h"
#include "BRFImporterStructs.h"

namespace BRFImporter
{
	class Fetch : BRFImporterClass
	{
	protected:
		std::ifstream file;
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

		void LoadFile(std::string fileName);

		Fetch(std::string fileName);
		Fetch();
		~Fetch();

	};
}
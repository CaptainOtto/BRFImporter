#pragma once
#include "BRFImporterClass.h"
#include "BRFImporterStructs.h"
#include "MeshData.h"
#include "LightData.h"
#include <fstream>
#include <iostream>

namespace BRFImporter
{
	class Fetch : BRFImporterClass
	{
	protected:
		std::ifstream file;
		Fetch();
	public:
		void MeshDataContainer();
		void MaterialData();
		void SkeletonData();
		void GroupData();
		void LightData();
		void AttrData();
		void CameraData();
		void MorphAnimData();
		void AnimationData();

		void LoadFile(std::string fileName);

		~Fetch();
	};
}
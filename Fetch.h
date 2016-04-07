#pragma once
#include "BRFImporterClass.h"
#include <fstream>
#include <iostream>

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
		void LoadFile(std::string fileName);

		Fetch(std::string fileName);
		Fetch();
		~Fetch();

	};
}
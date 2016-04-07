#pragma once
#include "BRFImporterClass.h"
#include <fstream>
#include <iostream>
#include "BRFImporterStructs.h"
#include "MeshData.h"
#include "LightData.h"

namespace BRFImporter
{
	class Fetch : BRFImporterClass
	{
	protected:
		std::ifstream file;

	private:

		~Fetch();

	public:

		void MaterialData();

		void SkeletonData();

		void GroupData();

		void LightData();

		void AttrData();

		void CameraData();

		void MorphAnimData();

		void AnimationData();

		void MeshData();

		void LoadFile(std::string fileName);

		Fetch();

	};
}
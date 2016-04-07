#pragma once
#include "BRFImporterClass.h"
#include <fstream>
#include <iostream>
#include "BRFImporterStructs.h"

namespace BRFImporter
{
	class Fetch : BRFImporterClass
	{
	private:
		std::ifstream file;
		BRFImporter::MeshHeader meshStruct;

	public:

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
		~Fetch();

		void MeshData(char * fileInfo, char length);

	};
}
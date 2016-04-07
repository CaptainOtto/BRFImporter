#pragma once
#include "BRFImporterClass.h"
#include "BRFImporterStructs.h"
#include "MeshData.h"
#include "LightData.h"

namespace BRFImporter
{
	class Fetch : BRFImporterClass
	{
	protected:
		std::ifstream file;
<<<<<<< HEAD
	private:
=======

	private:

		~Fetch();
>>>>>>> refs/remotes/origin/Otto-branch

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

		void MeshData();

<<<<<<< HEAD
		Fetch(std::string fileName);
		Fetch();
		~Fetch();

=======
		void LoadFile(std::string fileName);

		Fetch();

>>>>>>> refs/remotes/origin/Otto-branch
	};
}
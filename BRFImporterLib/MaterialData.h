#pragma once
#include <memory>
#include <vector>
#include <string>
#include "BRFImporterStructs.h"

namespace BRFImporterLib
{
	class MaterialData
	{
	protected:
		std::vector<std::shared_ptr<MaterialContainer>> materialContainer;
	public:
		void SetData(std::shared_ptr<MaterialContainer> SrcMaterialData);
		MaterialContainer* GetMaterialData(unsigned int materialID);
		MaterialData();
		~MaterialData();
	};
}


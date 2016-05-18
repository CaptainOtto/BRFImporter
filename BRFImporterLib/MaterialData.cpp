#include "MaterialData.h"
using namespace BRFImporterLib;

void MaterialData::SetData(std::shared_ptr<MaterialContainer> SrcMaterialData)
{
	materialContainer.push_back(SrcMaterialData);
}
MaterialContainer* MaterialData::GetMaterialData(unsigned int materialID)
{
	return this->materialContainer[materialID].get();
}

//CON DECON
MaterialData::MaterialData()
{
}

MaterialData::~MaterialData()
{
}

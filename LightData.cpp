#include "LightData.h"

BRFImporter::SpotLightHeader BRFImporter::LightData::SpotLightData()
{
	return this->spotLightData;
}

BRFImporter::AmbLightHeader BRFImporter::LightData::AmbLightData()
{
	return this->ambLightData;
}

BRFImporter::AreaLightHeader BRFImporter::LightData::AreaLightData()
{
	return this->areaLightData;
}

BRFImporter::PointLightHeader BRFImporter::LightData::PointLightData()
{
	return this->pointLightData;
}

BRFImporter::DirLightHeader BRFImporter::LightData::DirLightData()
{
	return this->dirLightData;
}

BRFImporter::LightData::LightData(SpotLightHeader spotLightData, AmbLightHeader ambLightData, AreaLightHeader areaLightData, PointLightHeader pointLightData, DirLightHeader dirLightData)
{
	this->spotLightData = spotLightData;
	this->ambLightData = ambLightData;
	this->areaLightData = areaLightData;
	this->pointLightData = pointLightData;
	this->dirLightData = dirLightData;
}
//CON
BRFImporter::LightData::LightData()
{

}
//DECON
BRFImporter::LightData::~LightData()
{

}

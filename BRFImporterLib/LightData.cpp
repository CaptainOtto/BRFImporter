#include "LightData.h"
using namespace BRFImporterLib;

LightHeader LightData::GetLightData()
{
	return this->lightData;
}
SpotLightHeader* LightData::GetSpotLightData()
{
	return this->spotLightData;
}
AreaLightHeader* LightData::GetAreaLightData()
{
	return this->areaLightData;
}
PointLightHeader* LightData::GetPointLightData()
{
	return this->pointLightData;
}
DirLightHeader* LightData::GetDirLightData()
{
	return this->dirLightData;
}

//CON DECON
LightData::LightData()
{

}
LightData::~LightData()
{

}
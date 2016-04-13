#include "LightData.h"
using namespace BRFImporterLib;

LightHeader LightData::getLightData()
{
	return this->lightData;
}
SpotLightHeader* LightData::getSpotLightData()
{
	return this->spotLightData;
}
AreaLightHeader* LightData::getAreaLightData()
{
	return this->areaLightData;
}
PointLightHeader* LightData::getPointLightData()
{
	return this->pointLightData;
}
DirLightHeader* LightData::getDirLightData()
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
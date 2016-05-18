#include "LightData.h"
#include <crtdbg.h>
using namespace BRFImporterLib;
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)

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
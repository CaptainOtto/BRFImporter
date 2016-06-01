#include "LightData.h"
#include <crtdbg.h>
using namespace BRFImporterLib;
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)


void LightData::SetData(std::shared_ptr<LightContainer> SrcLightData)
{
	this->lightDataContainer = SrcLightData;
}

LightHeader* LightData::GetLightData()
{
	return this->lightDataContainer->lightData.get();
}

SpotLightHeader LightData::GetSpotLightData(unsigned int iD)
{
	return this->lightDataContainer->spotLightData.get()[iD];
}

AreaLightHeader LightData::GetAreaLightData(unsigned int iD)
{
	return this->lightDataContainer->areaLightData.get()[iD];
}

PointLightHeader LightData::GetPointLightData(unsigned int iD)
{
	return this->lightDataContainer->pointLightData.get()[iD];
}

DirLightHeader LightData::GetDirLightData(unsigned int iD)
{
	return this->lightDataContainer->dirLightData.get()[iD];
}

//CON DECON
LightData::LightData()
{

}

LightData::~LightData()
{

}

LightContainer::LightContainer(
	unsigned int spotCount,
	unsigned int areaCount,
	unsigned int pointCount,
	unsigned int dirCount
)
{
	this->lightData = std::shared_ptr<LightHeader>(new LightHeader);

	this->spotLightData = std::unique_ptr<SpotLightHeader[]>(new SpotLightHeader[spotCount]);
	this->areaLightData = std::unique_ptr<AreaLightHeader[]>(new AreaLightHeader[areaCount]);
	this->pointLightData = std::unique_ptr<PointLightHeader[]>(new PointLightHeader[pointCount]);
	this->dirLightData = std::unique_ptr<DirLightHeader[]>(new DirLightHeader[dirCount]);
}

LightContainer::~LightContainer()
{
	this->lightData.reset();
	this->spotLightData.reset();
	this->areaLightData.reset();
	this->pointLightData.reset();
	this->dirLightData.reset();
}


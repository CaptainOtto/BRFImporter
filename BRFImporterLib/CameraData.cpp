#include "CameraData.h"
#include <crtdbg.h>
#define new new(_NORMAL_BLOCK,__FILE__,__LINE__)

using namespace BRFImporterLib;



CameraHeader * CameraData::getCameraData()
{
	return this->cameraDataContainer->getCameraData();
}

void BRFImporterLib::CameraData::SetData(std::shared_ptr<CameraContainer> source)
{
	this->cameraDataContainer = source;
}

CameraData::CameraData()
{

}

CameraData::~CameraData()
{

}

CameraHeader * CameraContainer::getCameraData()
{
	return this->cameraData.get();
}

CameraContainer::CameraContainer()
{

}

CameraContainer::~CameraContainer()
{

}

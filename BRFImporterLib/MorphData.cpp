#include "MorphData.h"
using namespace BRFImporterLib;
BRFImporterLib::MorphData::MorphData()
{
}

BRFImporterLib::MorphData::~MorphData()
{
}

void BRFImporterLib::MorphData::setData(std::shared_ptr<MorphDataContainer> srcMorphData)
{
	this->morphDataContainer = srcMorphData;
}

BRFImporterLib::MorphDataContainer::MorphDataContainer(unsigned int numberOfKeyFrames, unsigned int vertPerShape)
{
	this->morphKeyFrameData = std::unique_ptr<MorphAnimKeyFrameHeader[]>(new MorphAnimKeyFrameHeader[numberOfKeyFrames]);
	this->morphVertexData = std::unique_ptr<std::vector<MorphVertexHeader>[]>(new std::vector<MorphVertexHeader>[numberOfKeyFrames]);
}

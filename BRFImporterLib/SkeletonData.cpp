#include "SkeletonData.h"
using namespace BRFImporterLib;

void SkeletonData::setData(std::shared_ptr<SkeletonContainer> srcSkeletonData)
{
	this->skeletonDataContainer = srcSkeletonData;
}

SkeletonData::SkeletonData()
{
}

SkeletonData::~SkeletonData()
{
}
FrameHeader SkeletonData::GetAnimationID(unsigned int id)
{
	return this->skeletonDataContainer->frameDataContainer.get()->frameData[id];
}
SkeletonHeader SkeletonData::GetSkeletonID(unsigned int id)
{
	return this->skeletonDataContainer->skeletonData.get()->Id[];
}
//CON DECON

SkeletonContainer::SkeletonContainer(unsigned int jointCount, unsigned int animationCount)
{
	this->skeletonData = std::shared_ptr<SkeletonHeader>(new SkeletonHeader);
	this->jointData = std::unique_ptr<JointHeader[]>(new JointHeader[jointCount]);
	this->animationData = std::unique_ptr<AnimationHeader[]>(new AnimationHeader[animationCount]);

	this->frameDataContainer = std::unique_ptr<FrameDataContainer[]>(new FrameDataContainer(this->animationData.get()->jointCount));
}

FrameDataContainer::FrameDataContainer(unsigned int jointCount)
{
	this->animationJointData = std::shared_ptr<JointCountHeader>(new JointCountHeader[jointCount]);
}
SkeletonContainer::~SkeletonContainer()
{

}
FrameDataContainer::~FrameDataContainer()
{

}


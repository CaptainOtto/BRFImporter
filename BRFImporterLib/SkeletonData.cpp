#include "SkeletonData.h"
using namespace BRFImporterLib;

//SKELETON
void SkeletonData::setData(std::shared_ptr<SkeletonContainer> srcSkeletonData)
{
	this->skeletonDataContainer = srcSkeletonData;
}

AnimationHeader* SkeletonData::GetAnimation(unsigned int id)
{
	return &this->skeletonDataContainer->animationData[id];
}

unsigned int SkeletonData::GetAnimationID(unsigned int id)
{
	return this->skeletonDataContainer->animationData[id].animationID;
}

SkeletonHeader* SkeletonData::GetSkeletonData()
{
	return this->skeletonDataContainer->skeletonData.get();
}

//CON DECON
SkeletonData::SkeletonData()
{
}

SkeletonData::~SkeletonData()
{
}

//SKELETON DATA CONTAINER
SkeletonContainer::SkeletonContainer(unsigned int jointCount, unsigned int animationCount)
{
	this->skeletonData = std::shared_ptr<SkeletonHeader>(new SkeletonHeader);
	this->jointData = std::unique_ptr<JointHeader[]>(new JointHeader[jointCount]);
	this->animationData = std::unique_ptr<AnimationHeader[]>(new AnimationHeader[animationCount]);
}
void SkeletonContainer::SetFrameDataContainer(unsigned int animationJointCount)
{
	for (unsigned int i = 0; i < animationJointCount; i++)
	{
		this->frameDataContainer.push_back(std::shared_ptr<FrameDataContainer>(new FrameDataContainer(animationJointCount)));
	}
}

//CON DECON
SkeletonContainer::SkeletonContainer()
{

}
SkeletonContainer::~SkeletonContainer()
{

}

//SKELETON FRAME DATA CONTAINER
//CON DECON
FrameDataContainer::FrameDataContainer(unsigned int jointCount)
{
	this->animationJointData = std::shared_ptr<JointCountHeader>(new JointCountHeader[jointCount]);
}

FrameDataContainer::~FrameDataContainer()
{

}



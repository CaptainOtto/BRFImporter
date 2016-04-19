#pragma once
#include <memory>
#include <vector>
#include <string>
#include "BRFImporterStructs.h"

namespace BRFImporterLib
{
	class FrameDataContainer
	{
	public:
		std::shared_ptr<JointCountHeader> animationJointData;
		std::vector<std::shared_ptr<FrameHeader>> frameData;

		FrameDataContainer(unsigned int animatedJointCount); //new på ptrs
		~FrameDataContainer();
	};

	class SkeletonContainer
	{
	public:
		std::shared_ptr<SkeletonHeader> skeletonData;
		std::unique_ptr<JointHeader[]> jointData;
		std::unique_ptr<AnimationHeader[]> animationData;
		std::unique_ptr<FrameDataContainer[]> frameDataContainer;

		//CON DECON
		SkeletonContainer(unsigned int jointCount, unsigned int animationCount);
		~SkeletonContainer();

	};
	class SkeletonData
	{
	protected:
		std::shared_ptr<SkeletonContainer> skeletonDataContainer;

	public:
		void setData(std::shared_ptr<SkeletonContainer> srcSkeletonData);
		FrameHeader GetAnimationID(unsigned int id);
		SkeletonHeader GetSkeletonID(unsigned int id);
		SkeletonData();
		~SkeletonData();
	};
}
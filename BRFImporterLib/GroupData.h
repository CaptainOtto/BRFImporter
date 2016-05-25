#pragma once
#include <memory>
#include "BRFImporterStructs.h"

namespace BRFImporterLib
{
	//class GroupContainer
	//{
	//public:
	//	//std::shared_ptr<GroupHeader> groupData;
	//	
	//	GroupContainer();
	//	~GroupContainer();
	//};

	class GroupData
	{
	protected:
		//std::shared_ptr<GroupContainer> groupDataContainer;
		std::shared_ptr<GroupHeader> groupData;
	public:
		GroupHeader* getGroupData();
		GroupData();
		~GroupData();
	};
}



#include "GroupData.h"
#include <crtdbg.h>
#define new new(_NORMAL_BLOCK,__FILE__,__LINE__)

using namespace BRFImporterLib;



GroupContainer * GroupData::getGroupData()
{
	return this->groupDataContainer.get();
}

void BRFImporterLib::GroupData::SetData(std::shared_ptr<GroupContainer> source)
{

	this->groupDataContainer = source;

}

//CON DECON
GroupData::GroupData()
{
}


GroupData::~GroupData()
{
}



//GroupContainer CLASS

GroupContainer::GroupContainer(unsigned int attributeCount)
{
	attributeType = std::unique_ptr<GroupAttributeHeader[]>(new GroupAttributeHeader[attributeCount]);

}

GroupContainer::~GroupContainer()
{


}
GroupHeader* GroupContainer::getGroupData()
{
	return this->groupData.get();
}
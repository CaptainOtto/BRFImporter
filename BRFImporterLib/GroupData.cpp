#include "GroupData.h"
#include <crtdbg.h>
#define new new(_NORMAL_BLOCK,__FILE__,__LINE__)

using namespace BRFImporterLib;



GroupHeader * GroupData::getGroupData()
{
	return this->groupDataContainer->getGroupData();
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

GroupContainer::GroupContainer()
{

}

GroupContainer::~GroupContainer()
{


}
GroupHeader* GroupContainer::getGroupData()
{
	return this->groupData.get();
}